#makefile for matrix manager

CC = g++

LINKERFLAGS = -lm

SRCS := $(wildcard classes/*.cpp)
OBJS := $(SRCS:%.cpp=%.o)
DRIVER := driver.cpp
TESTER := test.cpp

EXE := build		#name of executable



all: ${EXE}

${EXE}: ${OBJS} ${DRIVER}
	@echo "Building..."
	${CC} -o $@ $^

test: ${OBJS} ${TESTER}
	@echo "Creating test..."
	${CC} -o $@ $^
	@echo "Running test..."
	./$@

%.o: %.cpp
	@echo "Creating objects..."
	${CC} -c $<

clean:
	@echo "Cleaning up..."
	rm -f ${EXE}
	rm -f test
	rm *.o