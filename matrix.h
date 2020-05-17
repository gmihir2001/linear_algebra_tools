#ifndef MATRIX_H
#define MATRIX_H

#include "rational.h"

struct matrix {

	unsigned int rows;
	unsigned int cols;

	struct rational **arr;
};

void matrix_zero_init(struct matrix *mat, int rows, int cols);
void matrix_init(struct matrix *mat, int rows, int cols, struct rational *input);

// multiply each element in the given row by the scalar.
// (Basic row operation)
void matrix_row_mult(struct matrix *mat, int row, int scalar);

void matrix_row_divide(struct matrix *mat, int row, int scalar);

void matrix_print(struct matrix *mat);

void matrix_row_swap(struct matrix *mat, int row_a, int row_b);

void matrix_row_add_multiple(struct matrix *mat, int row_a, int row_z, int scalar);

// general operations

// multipy by a scalar (fraction)
// add two matrices together.
// trace of a matrix.
struct rational matrix_trace(struct matrix *mat);

// transpose of a matrix
// store the transpose into T.
// matrix A is unchnaged.
void matrix_transpose(struct matrix *T, struct matrix *A);

// sum of two matrices
// store the sum into matrix C.
// matrix A and B are unchanged.
void matrix_add(struct matrix *C, struct matrix *A, struct matrix *B);

// product of two matrices.
// store the product into matrix C.
// matrix A and B are unchanged.
void matrix_mult(struct matrix *C, struct matrix *A, struct matrix *B);

// inverse of a 2x2 matrix.
// store the inverse into matrix inv.
// matrix A is unchanged.
void matrix_inv_2x2(struct matrix *inv, struct matrix *A);

// inverse of a 3x3 matrix.
// store the inverse into matrix inv.
// matrix A is unchanged.
void matrix_inv_3x3(struct matrix *inv, struct matrix *A);

#endif
