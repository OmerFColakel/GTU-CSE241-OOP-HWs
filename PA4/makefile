.PHONY: compile clean

CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -fstack-protector-strong -std=c++11
LDFLAGS =
SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRCFILES:.cpp=.o)
TARGET = program

compile: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm $(TARGET) $(OBJFILES)
