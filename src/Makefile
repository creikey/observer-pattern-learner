.PHONY: all clean debug

FLAGS=-Wall
LIBS=-lnerror
CXX=g++
CPPFILES=$(wildcard *.cpp)

all:
	$(CXX) $(FLAGS) $(CPPFILES) $(LIBS)

clean:
	-rm -f a.out

debug: FLAGS += -g
debug: clean all