EXECS=main
MPICC?=mpicxx

all: ${EXECS}

main: main.cpp
	${MPICC} -o main main.cpp

clean:
	rm -f ${EXECS}