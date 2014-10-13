SHELL=/bin/bash

MKTARGETDIR={ mkdir -p $(@D); }
TOUCHTARGET={ $(MKTARGETDIR) && touch $@; }

CXX=g++
CXXFLAGS=-Wall
RM=rm -f --

HDR=$(shell find src -name '*.h')
SRC=$(shell find src -name '*.cpp')
OBJ=$(SRC:.cpp=.o)

TESTSRC=$(shell find test -name '*.cpp')
TESTOBJ=$(TESTSRC:.cpp=.o)
TESTBIN=$(TESTSRC:.cpp=.test)

ALLSRC=$(SRC) $(TESTSRC)

INC=-Isrc -Itest/lib
LIBCLANG_PATH=/usr/lib/llvm-3.4/lib

LINK=$(CXX) $(CXXFLAGS) -o $@ $^
COMPILE=$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $<

all: $(OBJ)

-include .make/dependencies

test: $(TESTBIN)

%.test: %.o
	$(LINK)

%.o: %.cpp
	$(COMPILE)

doc: $(SRC) $(HDR)
	LD_LIBRARY_PATH=$(LIBCLANG_PATH) cldoc generate -- --report --merge docs --output doc $^

viewdocs:
	cldoc serve doc

clean:
	$(RM) $(OBJ) $(TESTOBJ) $(TESTBIN)

.make/dependencies: $(ALLSRC) $(HDR)
	$(MKTARGETDIR) && { $(foreach src,$(ALLSRC),$(CXX) $(INC) -MT $(src:.cpp=.o) -MM $(src);) } > $@

