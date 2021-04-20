#makefile for matrix manager

CC = g++

LINKERFLAGS = -lm

SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:%.cpp=%.o)

EXE := test

# all: ${BINS}
# 
# %: %.o
# 	@echo "Linking files..."
# 	${CC} ${LINKERFLAGS} $< -o $@
# 
# 
# %.o: %.c
# 	@echo "Creating objects..."
# 	${CC} -c $<
# 
# 
# clean:
# 	@echo "cleaning up..."
# 	trash *.o ${BINS}


all: ${EXE}

${EXE}: ${OBJS}
	@echo "Linking..."
	${CC} -o $@ $^

%.o: %.cpp
	@echo "Creating objects..."
	${CC} -c $<

clean:
	@echo "Cleaning up..."
	rm ${EXE}