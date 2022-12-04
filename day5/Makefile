CXX=g++
CXXFLAGS=-O1 -std=c++11

all: run
run: day5
	./day5

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

day5: day5.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f day5.o day5
