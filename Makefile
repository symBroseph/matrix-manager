#makefile for matrix manager

CC = g++

SRCS := $(wildcard *.cpp)
BINS := $(SRCS:%.cpp=%)

all: ${BINS}

%: %.o
	@echo "Linking files..."
	${CC} $< -o $@


%.o: %.c
	@echo "Creating objects..."
	${CC} -c $<


clean:
	@echo "cleaning up..."
	trash *.o ${BINS}


