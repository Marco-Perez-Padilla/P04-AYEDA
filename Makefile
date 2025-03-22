CXX = g++
CXXFLAGS = -std=c++23 -Wall -g

SOURCES = $(wildcard *.cc)
OBJ = $(SOURCES:.cc=.o)

EXECUTABLE = p04_hash_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXECUTABLE)
