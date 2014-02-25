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
	($(foreach src,$(SRC),$(CXX) $(INC) -MT $(src:.cpp=.o) -MM $(src);)) >> Makefile

# DEPENDENCIES
ansi/color.o: ansi/color.cpp ../src/ansi/color.h
controller/infinite_angle.o: controller/infinite_angle.cpp \
 ../src/controller/infinite_angle.h ../src/math/util.h \
 ../src/meta/is_real.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/meta/false.h ../src/meta/param.h \
 ../src/meta/cref.h ../src/meta/minsize.h ../src/meta/if.h \
 ../src/meta/is_pod.h ../src/meta/is_primitive.h ../src/meta/is_pointer.h \
 ../src/meta/ref.h ../src/unit_test.h ../src/ansi/color.h
controller/clamped.o: controller/clamped.cpp ../src/controller/clamped.h \
 ../src/math/util.h ../src/meta/is_real.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h \
 ../src/meta/param.h ../src/meta/cref.h ../src/meta/minsize.h \
 ../src/meta/if.h ../src/meta/is_pod.h ../src/meta/is_primitive.h \
 ../src/meta/is_pointer.h ../src/meta/ref.h ../src/unit_test.h \
 ../src/ansi/color.h
controller/switcher.o: controller/switcher.cpp \
 ../src/controller/switcher.h ../src/meta/param.h ../src/meta/cref.h \
 ../src/meta/minsize.h ../src/meta/if.h ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/meta/false.h ../src/meta/is_pointer.h \
 ../src/meta/ref.h ../src/unit_test.h ../src/ansi/color.h \
 ../src/math/util.h ../src/meta/is_real.h
controller/button_duo.o: controller/button_duo.cpp \
 ../src/controller/button_duo.h ../src/unit_test.h ../src/ansi/color.h
datastruct/array_tuple.o: datastruct/array_tuple.cpp \
 ../src/datastruct/array_tuple.h ../src/meta/param.h ../src/meta/cref.h \
 ../src/meta/minsize.h ../src/meta/if.h ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/meta/false.h ../src/meta/is_pointer.h \
 ../src/meta/ref.h ../src/functional/operators.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/math/util.h ../src/meta/is_real.h
datastruct/tuple.o: datastruct/tuple.cpp ../src/datastruct/tuple.h \
 ../src/meta/param.h ../src/meta/cref.h ../src/meta/minsize.h \
 ../src/meta/if.h ../src/meta/is_pod.h ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h ../src/meta/is_pointer.h ../src/meta/ref.h \
 ../src/meta/int.h ../src/meta/choose.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/math/util.h ../src/meta/is_real.h
meta/bool.o: meta/bool.cpp ../src/meta/bool.h ../src/meta/constant.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/false.o: meta/false.cpp ../src/meta/false.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/unit_test.h ../src/ansi/color.h
meta/and.o: meta/and.cpp ../src/meta/and.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/is_pointer.o: meta/is_pointer.cpp ../src/meta/is_pointer.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/is_real.o: meta/is_real.cpp ../src/meta/is_real.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/cref.o: meta/cref.cpp ../src/meta/cref.h ../src/meta/minsize.h \
 ../src/meta/if.h ../src/meta/is_pod.h ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h ../src/meta/is_pointer.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/meta/same_type.h
meta/is_pod.o: meta/is_pod.cpp ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/meta/false.h ../src/meta/is_pointer.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/same_type.o: meta/same_type.cpp ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h ../src/unit_test.h ../src/ansi/color.h
meta/choose.o: meta/choose.cpp ../src/meta/choose.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/meta/same_type.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h
meta/constant.o: meta/constant.cpp ../src/meta/constant.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/if.o: meta/if.cpp ../src/meta/if.h ../src/unit_test.h \
 ../src/ansi/color.h ../src/meta/same_type.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h
meta/is_primitive.o: meta/is_primitive.cpp ../src/meta/is_primitive.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h ../src/unit_test.h ../src/ansi/color.h
meta/ref.o: meta/ref.cpp ../src/meta/ref.h ../src/meta/if.h \
 ../src/unit_test.h ../src/ansi/color.h ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h
meta/minsize.o: meta/minsize.cpp ../src/meta/minsize.h ../src/meta/if.h \
 ../src/unit_test.h ../src/ansi/color.h ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h
meta/true.o: meta/true.cpp ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/unit_test.h ../src/ansi/color.h
meta/int.o: meta/int.cpp ../src/meta/int.h ../src/meta/constant.h \
 ../src/unit_test.h ../src/ansi/color.h ../src/meta/same_type.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/false.h
meta/or.o: meta/or.cpp ../src/meta/or.h ../src/meta/true.h \
 ../src/meta/bool.h ../src/meta/constant.h ../src/meta/false.h \
 ../src/unit_test.h ../src/ansi/color.h
meta/param.o: meta/param.cpp ../src/meta/param.h ../src/meta/cref.h \
 ../src/meta/minsize.h ../src/meta/if.h ../src/meta/is_pod.h \
 ../src/meta/is_primitive.h ../src/meta/true.h ../src/meta/bool.h \
 ../src/meta/constant.h ../src/meta/false.h ../src/meta/is_pointer.h \
 ../src/unit_test.h ../src/ansi/color.h ../src/meta/same_type.h
math/util.o: math/util.cpp ../src/math/util.h ../src/meta/is_real.h \
 ../src/meta/true.h ../src/meta/bool.h ../src/meta/constant.h \
 ../src/meta/false.h ../src/unit_test.h ../src/ansi/color.h
