#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void matrix_zero_init(struct matrix *mat, int rows, int cols) {

	mat->rows = rows;
	mat->cols = cols;

	mat->arr = malloc(sizeof(struct rational *) * rows);

	for(int i = 0; i < mat->rows; i++) {
		mat->arr[i] = malloc(sizeof(struct rational) * cols);
	}

	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			mat->arr[i][j] = rational_create(0, 1);
		}
	}
}

// assume that the input has valid memory with rows number of rows
// and cols number of columns.
void matrix_init(struct matrix *mat, int rows, int cols, struct rational *input) {

	mat->rows = rows;
	mat->cols = cols;

	mat->arr = malloc(sizeof(struct rational *) * rows);

	for(int i = 0; i < mat->rows; i++) {
		mat->arr[i] = malloc(sizeof(struct rational) * cols);
	}

	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			mat->arr[i][j] = input[cols * i + j];
		}
	}
}

void matrix_row_swap(struct matrix *mat, int row_a, int row_b) {
	struct rational temp;
	for(int i = 0; i<mat->cols; i++) {
		temp = mat->arr[row_a][i];
		mat->arr[row_a][i] = mat->arr[row_b][i];
		mat->arr[row_b][i] = temp;
	}
}

void matrix_row_add_multiple(struct matrix *mat, int row_a, int row_z, int scalar) {

	struct rational s = rational_create(scalar, 1);
	for(int i = 0; i<mat->cols; i++) {
		struct rational temp  = rational_mult( mat->arr[row_z][i], s);
		mat->arr[row_a][i] = rational_add(mat->arr[row_a][i], temp);
	}
}

void matrix_row_mult(struct matrix *mat, int row, int scalar) {

	struct rational s = rational_create(scalar, 1);

	for(int i = 0; i<mat->cols; i++) {
		mat->arr[row][i] = rational_mult( mat->arr[row][i], s);
	}
}


void matrix_row_divide(struct matrix *mat, int row, int scalar) {

	struct rational s = rational_create(scalar, 1);

	for(int i = 0; i<mat->cols; i++) {
		mat->arr[row][i] = rational_div( mat->arr[row][i], s);
	}
}


void matrix_print(struct matrix *mat) {
	for(int i = 0; i < mat->rows; i++) {
		for(int j = 0; j < mat->cols; j++) {
			rational_print(mat->arr[i][j]);
		}

		printf("\n");
	}
}


struct rational matrix_trace(struct matrix *mat) {

	struct rational sum = rational_create(0, 1);

	if (mat->cols != mat->rows) {
		return sum;
	}

	for (int i = 0; i < mat->rows; i++) {
		sum = rational_add(mat->arr[i][i], sum);
	}

	return sum;
}


void matrix_add(struct matrix *C, struct matrix *A, struct matrix *B) {

	// check that the rows and cols are the same
	// (code here)
	if(A->cols != B->cols) {
		//error
		return;
	}
	if(A->rows != B->rows) {
		//error
		return;
	}

	matrix_zero_init(C, A->rows, A->cols);

	// do adding stuff
	for (int i = 0; i < A->rows; i++ ) {
		for (int j = 0; j < A->cols; j++) {
			C->arr[i][j] = rational_add(A->arr[i][j], B->arr[i][j]);
		}
	}
}

void matrix_transpose(struct matrix *T, struct matrix *A) {

	// A transpose matrix has transposed number of
	// columns and rows. (The transpose of a 3x4 matrix
	// will have dimensions 4x3)
	matrix_zero_init(T, A->cols, A->rows);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < A->cols; j++) {
			T->arr[j][i] = A->arr[i][j];
		}

	}
}

void matrix_mult(struct matrix *C, struct matrix *A, struct matrix *B) {
	if (A->cols != B->rows) {
		return;
	}

	matrix_zero_init(C, A->rows, B->cols);

	for (int i = 0; i < A->rows; i++) {
		for (int j = 0; j < B->cols; j++) {

			struct rational sum = rational_create(0,1);

			for (int k = 0; k < A->cols; k++) {

				struct rational a_val = A->arr[i][k];
				struct rational b_val = B->arr[k][j];
				struct rational prod = rational_mult(a_val, b_val);

				sum = rational_add(prod, sum);
			}

			C->arr[i][j] = sum;
		}
	}
}
