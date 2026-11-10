CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS = -L/usr/local/lib -lgtest -lgtest_main -pthread

all: test

test: lltest
	./lltest

lltest: tests.cpp ll.h ll.ipp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)


clean:
	rm -f lltest *.o
