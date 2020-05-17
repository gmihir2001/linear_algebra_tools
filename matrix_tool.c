#include <stdio.h>
#include <string.h>

#include "rational.h"
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

	struct rational input_arr[64];

	for(int i = 0; i < (rows * cols); i++) {
		int input;
		scanf("%d", & input);
		input_arr[i] = rational_create(input, 1);
	}

	matrix_init(mat_01_ptr, rows, cols, input_arr);

	matrix_print(mat_01_ptr);

	// now we can do actual operations.
	printf("Matrix manipulation options:\n");
	printf("\t(s)wap rows: ...............  s [r1] [r2]\n");
	printf("\t(m)ult row by scalar: ......  m [r] [scalar]\n");
	printf("\t(d)ivide row by scalar: ....  d [r] [scalar]\n");
	printf("\t(a)dd mult of other row: ...  a [dest] [source] [scalar]\n");

	printf("\n");

	char command[32];

	do {
		printf("Please enter a command: ");
		scanf("%s", command);

		if ( strcmp(command, "s") == 0) {

			int r1;
			int r2;
			scanf("%d %d", &r1, &r2);
			matrix_row_swap(mat_01_ptr, r1 - 1, r2 - 1);
			matrix_print(mat_01_ptr);

		} else if ( strcmp(command, "m") == 0) {
			int r;
			int scalar;
			scanf("%d %d", &r, &scalar);
			matrix_row_mult(mat_01_ptr, r - 1, scalar);
			matrix_print(mat_01_ptr);
		} else if ( strcmp(command, "d") == 0) {
			int r;
			int scalar;
			scanf("%d %d", &r, &scalar);
			matrix_row_divide(mat_01_ptr, r - 1, scalar);
			matrix_print(mat_01_ptr);


		} else if ( strcmp(command, "a") == 0) {

			int r1;
			int r2;
			int scalar;
			scanf("%d %d %d", &r1, &r2, & scalar);
			matrix_row_add_multiple(mat_01_ptr, r1 - 1, r2 - 1, scalar);
			matrix_print(mat_01_ptr);


		} else if ( strcmp(command, "q") == 0) {
			printf("Goodbye!\n");
		} else {
			printf("Unrecognized operation!\n");
		}

	} while ( strcmp(command, "q") != 0);

	return 0;
}
