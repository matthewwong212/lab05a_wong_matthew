CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES=lab05Test

all: ${BINARIES}

lab05Test: lab05Test.o WordCount.o tddFuncs.o
	${CXX} $^ -o $@
	./lab05Test

clean:
	/bin/rm -f ${BINARIES} *.o