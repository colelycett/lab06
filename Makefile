CXX = g++
CXXFLAGS = --std=c++11 -Wall -Werror

test: lab06Test
	./lab06Test

lab06Test: lab06Test.o WordCount.o tddFuncs.o
	${CXX} ${CXXFLAGS} $^ -o $@  

clean:
	rm -f *.o lab06Test