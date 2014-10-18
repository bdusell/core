#!/usr/bin/env python

import sys, os, os.path, subprocess, re

DEFAULT_PATH = 'src'

usage = '''\
%s [options] [test-names ...]

    A test suite runner for C++ unit tests.

    options:
    --help                 Display this help message.
    --ignore-missing       Ignore missing tests.
    --first-failure        Stop after the first failure.
    --only-failures        Only display failures.
    --no-make-output       Suppress compilation output.
    --no-test-output       Suppress output from individual unit tests.
    --no-test-results      Show only the assertions for each test and no
                           result summary.
    --long                 Show the text for each assertion.
    --brief                Equivalent to --no-make-output --no-test-results.
    --                     End of options.

    test-names:
        A list of specific header/source files whose corresponding tests are to
        be run. Header/source file names map to test file names by changing the
        top-level directory from src/ to test/ and changing the file extension
        to .cpp.
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

def files_from_path(path):
    if os.path.isdir(path):
        return os.walk(path)
    else:
        path, basename = os.path.split(path)
        return [(path, [], [basename])]

def find_files(target_paths, extension):
    suffix = '.' + extension
    for target_path in target_paths:
        for (path, dirnames, filenames) in files_from_path(target_path):
            for name in filenames:
                if name.endswith(suffix):
                    yield os.path.join(path, name)

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
    return run_command(['make', filename], suppress) == 0

def run_test(filename, suppress, long_output, no_results):
    command = [filename]
    if not long_output:
        command.append('--dots')
    if suppress:
        command.append('--silent')
    if no_results:
        command.append('--no-result')
    return subprocess.call(command) == 0

def main():

    args = sys.argv[:0:-1]

    no_test_output = False
    no_make_output = False
    only_failures = False
    first_failure = False
    ignore_missing = False
    long_output = False
    no_test_results = False
    test_names = []
    while args:
        arg = args.pop()
        if arg == '--help' or arg == '-h':
            print usage
            sys.exit()
        elif arg == '--no-test-output':
            no_test_output = True
        elif arg == '--no-test-results':
            no_test_results = True
        elif arg == '--no-make-output':
            no_make_output = True
        elif arg == '--only-failures':
            only_failures = True
        elif arg == '--first-failure':
            first_failure = True
        elif arg == '--ignore-missing':
            ignore_missing = True
        elif arg == '--long':
            long_output = True
        elif arg == '--brief':
            no_make_output = no_test_results = True
        elif arg == '--':
            break
        else:
            test_names.append(arg)
    test_names.extend(reversed(args))

    test_file_names = find_files(test_names or [DEFAULT_PATH], 'h')

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
                if run_test(test_executable_name, no_test_output, long_output, no_test_results):
                    if not only_failures:
                        if not no_test_results:
                            log_message(green, 'test %s passed' % base_name)
                    passes += 1
                else:
                    if not no_test_results:
                        log_message(red, 'test %s failed' % base_name)
                if not no_test_output:
                    log_message(normal, '')
            else:
                log_message(red, 'compilation of %s failed' % test_source_name)
        elif not ignore_missing:
            log_message(red, 'test file %s is missing' % test_source_name)
            total += 1
        if first_failure and passes < total:
            break

    if total == 0:
        sys.stderr.write(red('error: no tests run') + '\n')
        sys.exit(1)

    failures = total - passes

    if not (first_failure and failures):
        log_message(cyan,   '==== TEST SUITE COMPLETE ====')
        log_message(normal, 'Total tests: %d' % total)
        log_message(red if failures else normal,
                            'Failures:    %d' % failures)
        log_message(green if passes else normal,
                            'Successes:   %d' % passes)

    if failures:
        sys.exit(1)

if __name__ == '__main__':
    main()

