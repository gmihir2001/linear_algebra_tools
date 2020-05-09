CC = gcc
CFLAGS = -Wall -Werror -std=c99

all: matrix_tool

matrix_tool: matrix.c matrix_tool.c
	$(CC) $(CFLAGS) matrix.c matrix_tool.c -o matrix_tool
	./matrix_tool

matrix_tests: matrix.c matrix_tests.c
	$(CC) $(CFLAGS) matrix.c matrix_tests.c -o matrix_tests
	./matrix_tests
