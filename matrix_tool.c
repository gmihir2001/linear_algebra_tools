#include <stdio.h>


#include "matrix.h"

int main(void) {

	struct matrix mat_01;
	struct matrix * mat_01_ptr = & mat_01;

	int arr[6] = {1, 2, 3, 4, 5, 6};

	matrix_init(mat_01_ptr, 2, 3, arr);

	matrix_print(mat_01_ptr);
	return 0;
}
