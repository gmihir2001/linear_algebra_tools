#include <stdio.h>
#include <stdint.h>

#include "matrix.h"

int main(void) {

	printf("Matrix Tests\n");

	// print and init test.

	struct matrix mat_01;
	struct matrix *mat_01_ptr = & mat_01;

	int input_2d_arr[] = {
		1, 2, 3, 8,
		4, 30, 90, 9,
		1, 2, 3, 4
	};

	struct rational input_rat_arr[12];

	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 4; j++) {
			input_rat_arr[i * 4 + j] = rational_create(input_2d_arr[i * 4 + j], 1);
		}
	}

	matrix_init(mat_01_ptr, 3, 4, input_2d_arr);

	matrix_row_add_multiple(mat_01_ptr, 1, 0, 2);

	matrix_print(mat_01_ptr);

	matrix_row_swap(mat_01_ptr, 0, 1);

	matrix_row_mult(mat_01_ptr, 2, 5);

	matrix_print(mat_01_ptr);

	return 0;
}
