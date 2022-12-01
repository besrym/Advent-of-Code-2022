CXX=g++
CXXFLAGS=-O1 -std=c++11

all: run
run: day1
	./day1

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

day1: day1.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f day1.o day1
