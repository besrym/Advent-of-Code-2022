CXX=g++
CXXFLAGS=-O1 -std=c++11

all: run
run: day4
	./day4

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

day4: day4.o
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f day4.o day4
