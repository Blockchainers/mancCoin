OUT=manccoin
SRC=src/*.cpp src/rpc/*.cpp lib/librpc.a
INCLUDE=src/vendor

CPP_FLAGS=-std=c++11 -g -Wall

all:
	g++ ${CPP_FLAGS} ${SRC} -I${INCLUDE} -o ${OUT}