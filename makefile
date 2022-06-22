CC=g++
CFLAGS=-std=c++11
TARGET=tp01

OBJ_DIR = ./obj
SRC_DIR = ./src
INCLUDE_DIR = ./include

./${TARGET}: ${OBJ_DIR}/Memory.o ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/Memory.o: ${INCLUDE_DIR}/Memory.hpp ${SRC_DIR}/Memory.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Memory.cpp -o ${OBJ_DIR}/Memory.o
	
${OBJ_DIR}/main.o: ${INCLUDE_DIR}/Memory.hpp ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o
	
clean:
	rm -f ${OBJ_DIR}/*
	rm tp01