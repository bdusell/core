CXX=g++
CXXFLAGS=-Wall
RM=rm -f

SRC=$(shell find -name '*.cpp')
OBJ=$(SRC:.cpp=.o)
BIN=$(OBJ:.o=.test)

INC=-I../src

LINK=$(CXX) $(CXXFLAGS) -o $@ $^
COMPILE=$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

all: $(BIN)

%.test: %.o
	$(LINK)

%.o: %.cpp
	$(COMPILE)

clean:
	$(RM) $(BIN) $(OBJ)

depend:
	sed -i '/^# DEPENDENCIES/q' Makefile
	$(CXX) $(INC) -MM $(SRC) >> Makefile

# DEPENDENCIES
color.o: ansi/color.cpp ../src/ansi/color.h
infinite_angle.o: controller/infinite_angle.cpp \
 ../src/controller/infinite_angle.h ../src/math/util.h \
 ../src/meta/is_real.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/false.h ../src/meta/param.h ../src/meta/cref.h \
 ../src/meta/minsize.h ../src/meta/if.h ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/is_pointer.h ../src/meta/ref.h \
 ../src/unit_test.h ../src/ansi/color.h
clamped.o: controller/clamped.cpp ../src/controller/clamped.h \
 ../src/math/util.h ../src/meta/is_real.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/false.h ../src/meta/param.h \
 ../src/meta/cref.h ../src/meta/minsize.h ../src/meta/if.h \
 ../src/meta/is_pod.h ../src/meta/is_primitive.h ../src/meta/is_pointer.h \
 ../src/meta/ref.h ../src/unit_test.h ../src/ansi/color.h
button_duo.o: controller/button_duo.cpp ../src/controller/button_duo.h \
 ../src/unit_test.h ../src/ansi/color.h
bool.o: meta/bool.cpp ../src/meta/bool.h ../src/unit_test.h \
 ../src/ansi/color.h
false.o: meta/false.cpp ../src/meta/false.h ../src/meta/bool.h \
 ../src/unit_test.h ../src/ansi/color.h
and.o: meta/and.cpp ../src/meta/and.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/false.h ../src/unit_test.h \
 ../src/ansi/color.h
is_pointer.o: meta/is_pointer.cpp ../src/meta/is_pointer.h \
 ../src/unit_test.h ../src/ansi/color.h
is_real.o: meta/is_real.cpp ../src/meta/is_real.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/false.h ../src/unit_test.h \
 ../src/ansi/color.h
cref.o: meta/cref.cpp ../src/meta/cref.h ../src/meta/minsize.h \
 ../src/meta/if.h ../src/meta/is_pod.h ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h \
 ../src/meta/is_pointer.h ../src/unit_test.h ../src/ansi/color.h \
 ../src/meta/same_type.h
is_pod.o: meta/is_pod.cpp ../src/meta/is_pod.h ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h \
 ../src/meta/is_pointer.h ../src/unit_test.h ../src/ansi/color.h
same_type.o: meta/same_type.cpp ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
if.o: meta/if.cpp ../src/meta/if.h ../src/unit_test.h ../src/ansi/color.h \
 ../src/meta/same_type.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/false.h
is_primitive.o: meta/is_primitive.cpp ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
ref.o: meta/ref.cpp ../src/meta/ref.h ../src/meta/if.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/meta/same_type.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/false.h
minsize.o: meta/minsize.cpp ../src/meta/minsize.h ../src/meta/if.h \
 ../src/unit_test.h ../src/ansi/color.h ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h
true.o: meta/true.cpp ../src/meta/true.h ../src/meta/bool.h \
 ../src/unit_test.h ../src/ansi/color.h
or.o: meta/or.cpp ../src/meta/or.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/false.h ../src/unit_test.h ../src/ansi/color.h
param.o: meta/param.cpp ../src/meta/param.h ../src/meta/cref.h \
 ../src/meta/minsize.h ../src/meta/if.h ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/false.h ../src/meta/is_pointer.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/meta/same_type.h
util.o: math/util.cpp ../src/math/util.h ../src/meta/is_real.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
