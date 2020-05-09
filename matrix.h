#ifndef MATRIX_H
#define MATRIX_H

struct matrix {

	unsigned int rows;
	unsigned int cols;

	int **arr;
};

void matrix_init(struct matrix *mat, int rows, int cols, int *input);


void matrix_print(struct matrix *mat);


#endif
