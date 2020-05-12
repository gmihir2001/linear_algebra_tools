#include <stdio.h>
#include <assert.h>

#include "rational.h"

int main(void) {

	printf("Rational Number Tests\n");

	// test the create function.
	{
		struct rational a = rational_create(3, 4);
		assert(a.num == 3 && a.den == 4);

		a = rational_create(0, 1);
		assert(a.num == 0 && a.den == 1);
	}

	// test the rational add function.
	{
		struct rational a = rational_create(3, 5);
		struct rational b = rational_create(4, 5);

		struct rational result = rational_add(a, b);
		struct rational ans = rational_create(7, 5);

		assert(rational_eq(result, ans));
	}


	return 0;
}
