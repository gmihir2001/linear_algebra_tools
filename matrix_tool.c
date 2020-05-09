#include <stdio.h>


#include "matrix.h"

int main(void) {

	struct matrix mat_01;
	struct matrix * mat_01_ptr = & mat_01;

	// get the info for the matrix.
	printf("Please enter the dimensions of the matrix: ");

	int rows = 0;
	int cols = 0;

	scanf("%d %d", & rows, & cols);

	printf("Please enter the matrix itself (flat form): ");

	// for now, just use an array that has 64 spots...
	// should be able to hold the data.

	int input_arr[64];

	for(int i = 0; i < (rows * cols); i++) {
		scanf("%d", & input_arr[i]);
	}

	matrix_init(mat_01_ptr, rows, cols, input_arr);

	matrix_print(mat_01_ptr);

	return 0;
}
