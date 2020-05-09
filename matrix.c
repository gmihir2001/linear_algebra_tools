#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

// assume that the input has valid memory with rows number of rows
// and cols number of columns.
void matrix_init(struct matrix *mat, int rows, int cols, int *input) {

	mat->rows = rows;
	mat->cols = cols;

	mat->arr = malloc(sizeof(int *) * rows);

	for(int i = 0; i < mat->rows; i++) {
		mat->arr[i] = malloc(sizeof(int) * cols);
	}

	// set them all to zero.
	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			mat->arr[i][j] = input[cols * i + j];
		}
	}
}

void matrix_print(struct matrix *mat) {
	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			printf("%d ", mat->arr[i][j]);
		}

		printf("\n");
	}
}
