CXX=g++
CXXFLAGS=-O1 -std=c++11

all: run
run: day3
	./day3

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

day3: day3.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f day3.o day3
