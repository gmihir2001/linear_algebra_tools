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

void matrix_row_swap(struct matrix *mat, int row_a, int row_b) {
	int temp = 0;
	for(int i = 0; i<mat->cols; i++) {
		temp = mat->arr[row_a][i];
		mat->arr[row_a][i] = mat->arr[row_b][i];
		mat->arr[row_b][i] = temp;
	}
}
void matrix_row_add_multiple(struct matrix *mat, int row_a, int row_z, int scalar) {

	for (int i = 0; i < mat->cols; i++) {
		mat->arr[row_a][i] += mat->arr[row_z][i] * scalar;
	}
}
void matrix_row_mult(struct matrix *mat, int row, int scalar) {

	for(int i = 0; i<mat->cols; i++) {
		mat->arr[row][i] *= scalar;
	}
}


void matrix_row_divide(struct matrix *mat, int row, int scalar) {

	for(int i = 0; i<mat->cols; i++) {
		mat->arr[row][i] /= scalar;
	}

}


void matrix_print(struct matrix *mat) {
	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			printf("%8d ", mat->arr[i][j]);
		}

		printf("\n");
	}
}
