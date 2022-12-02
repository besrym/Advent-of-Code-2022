CXX=g++
CXXFLAGS=-O1 -std=c++11

all: run
run: day2
	./day2

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

day1: day1.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f day2.o day2
