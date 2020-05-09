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

	matrix_init(mat_01_ptr, 3, 4, input_2d_arr);
	return 0;
}
