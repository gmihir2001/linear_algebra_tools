#ifndef MATRIX_H
#define MATRIX_H

struct matrix {

	unsigned int rows;
	unsigned int cols;

	int **arr;
};

void matrix_init(struct matrix *mat, int rows, int cols, int *input);

// multiply each element in the given row by the scalar.
// (Basic row operation)
void matrix_row_mult(struct matrix *mat, int row, int scalar);

void matrix_print(struct matrix *mat);

void matrix_row_swap(struct matrix *mat, int row_a, int row_b);

#endif
