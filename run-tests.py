#!/usr/bin/env python

import sys, os, os.path, subprocess, re

usage = '''\
%s [options] [test-names ...]

    A test suite runner for C++ unit tests.

    options:
    --help                 Display this help message.
    --no-test-output       Suppress output from individual unit tests.
    --no-make-output       Suppress compilation output.
    --only-failures        Only display failures.
    --first-failure        Stop after the first failure.
    --ignore-missing       Ignore missing tests.
    --                     End of options.

    test-names:
    This may be a list of specific tests to run. These may be the names of
    header files, source files, or extension-less test names.
''' % (sys.argv[0])

def run_command(words, suppress=False):
    if suppress:
        with open(os.devnull, 'wb') as devnull:
            return subprocess.call(words, stdout=devnull, stderr=devnull)
    else:
        return subprocess.call(words)

def color(code, s):
    return '\033[%sm%s\033[0m' % (code, s)

def red(s):
    return color('31', s)

def cyan(s):
    return color('36', s)

def green(s):
    return color('32', s)

def normal(s):
    return s

def find_files(target_paths, extension):
    return (
        os.path.join(path, name)
        for target_path in target_paths
        for (path, dirnames, filenames) in os.walk(target_path)
        for name in filenames
        if name.endswith('.' + extension)
    )

test_name_pat = re.compile(r'^src/(.*?)(?:\.(?:h|cpp))?$')

def test_name_to_base_name(name):
    m = test_name_pat.match(name)
    return m and m.group(1)

def base_name_to_header_name(name):
    return 'src/%s.h' % (name)

def base_name_to_test_source_name(name):
    return 'test/%s.cpp' % (name)

def base_name_to_test_executable_name(name):
    return 'test/%s.test' % (name)

def compile_test(filename, suppress):
    return run_command(['make', filename]) == 0

def run_test(filename, suppress):
    return run_command([filename], suppress) == 0

def main():

    args = list(reversed(sys.argv[1:]))

    no_test_output = False
    no_make_output = False
    only_failures = False
    first_failure = False
    ignore_missing = False
    test_names = []
    while args:
        arg = args.pop()
        if arg == '--help' or arg == '-h':
            print usage
            sys.exit()
        elif arg == '--no-test-output':
            no_test_output = True
        elif arg == '--no-make-output':
            no_make_output = True
        elif arg == '--only-failures':
            only_failures = True
        elif arg == '--first-failure':
            first_failure = True
        elif arg == '--ignore-missing':
            ignore_missing = True
        elif arg == '--':
            break
        else:
            test_names.append(arg)
    test_names.extend(reversed(args))

    test_file_names = find_files(test_names or ['src'], 'h')

    def log_message(func, msg):
        print func(msg)

    total = 0
    passes = 0

    for test_name in test_file_names:
        base_name = test_name_to_base_name(test_name)
        header_name = base_name_to_header_name(base_name)
        test_source_name = base_name_to_test_source_name(base_name)
        test_executable_name = base_name_to_test_executable_name(base_name)
        if os.path.isfile(test_source_name):
            total += 1
            if compile_test(test_executable_name, no_make_output):
                if run_test(test_executable_name, no_test_output):
                    if not only_failures:
                        log_message(green, 'test %s passed' % base_name)
                    passes += 1
                else:
                    log_message(red, 'test %s failed' % base_name)
            else:
                log_message(red, 'compilation of %s failed' % test_source_name)
        elif not ignore_missing:
            log_message(red, 'test file %s is missing' % test_source_name)
            total += 1
        if first_failure and passes < total:
            break

    failures = total - passes

    if not (first_failure and failures):
        log_message(normal, '')
        log_message(cyan,   '==== TEST SUITE COMPLETE ====')
        log_message(normal, '')
        log_message(normal, 'Total tests: %d' % total)
        log_message(red if failures else normal,
                            'Failures:    %d' % failures)
        log_message(green if passes else normal,
                            'Successes:   %d' % passes)

    if failures:
        sys.exit(1)

if __name__ == '__main__':
    main()

