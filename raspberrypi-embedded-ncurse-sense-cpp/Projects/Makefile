# Makefile for building the examples distributed
# with SenseHat.

# Header files path (Update this with the library installation folder).
HEADERS_PATH = /usr/include

# Library path (Update this with the library installation folder).
LIBRARY_PATH = /usr/lib

# List of source files
SOURCES +=  menu.cpp test.cpp

#List of object files
OBJECTS += $(SOURCES:.cpp=.o)

all: test

#Compile all of the source files
%.o: %.cpp
	@echo Compiling file: $<
	g++ -I $(HEADERS_PATH) -std=c++0x -c $^ -o $@
	@echo


#Building test executable
test: test.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib -lcurses
	@echo

#Building menu executable
test: test.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib -lcurses
	@echo


# Uninstall the exemples from the system
uninstall:
	rm -f  test menu



.PHONY: clean
clean:
	rm -f *.o
