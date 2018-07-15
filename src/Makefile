.PHONY: all clean debug

FLAGS=-Wall
LIBS=-lnerror -lpthread
CXX=g++
CPPFILES=$(wildcard *.cpp)
HEADERS=$(wildcard *.hpp)
OBJECTFILES=$(CPPFILES:.cpp=.o)

%.o: %.cpp
	$(CXX) -c $(FLAGS) $< -o $@

all: $(OBJECTFILES) $(HEADERS)
	$(CXX) $(FLAGS) $(OBJECTFILES) $(LIBS)

clean:
	-rm -f a.out
	-rm -f $(OBJECTFILES)

debug: FLAGS += -g
debug: clean all