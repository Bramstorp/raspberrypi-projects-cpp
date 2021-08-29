# Makefile for building the examples distributed
# with SenseHat.

# Header files path (Update this with the library installation folder).
HEADERS_PATH = /usr/include

# Library path (Update this with the library installation folder).
LIBRARY_PATH = /usr/lib

# List of source files
SOURCES += text.cpp temp.cpp humi.cpp pressure.cpp menu.cpp

#List of object files
OBJECTS += $(SOURCES:.cpp=.o)

all: text temp humi pressure menu

#Compile all of the source files
%.o: %.cpp
	@echo Compiling file: $<
	g++ -I $(HEADERS_PATH) -std=c++0x -c $^ -o $@
	@echo


#Building text executable
text: text.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building temp executable
temp: temp.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building humi executable
humi: humi.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building humi executable
pressure: pressure.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo

#Building menu executable
menu: menu.o
	@echo Building target file: $@.
	g++ -L$(LIBRARY_PATH) -o $@ $^ -l SenseHat -l RTIMULib
	@echo


# Uninstall the exemples from the system
uninstall:
	rm -f  text temp humi pressure menu



.PHONY: clean
clean:
	rm -f *.o
