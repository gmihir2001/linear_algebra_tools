#include <stdio.h>

#include "rational.h"

struct rational rational_create(int num, int den) {
	struct rational ret;
	ret.num = num;
	ret.den = den;

	return ret;
}

struct rational rational_add(struct rational a, struct rational b) {
	struct rational result;

	result.num = a.num + b.num;
	result.den = a.den;

	return result;
}

bool rational_eq(struct rational a, struct rational b) {
	return (a.num == b.num && a.den == b.den);
}

void rational_print(struct rational a) {
	printf("%d/%d", a.num, a.den);
}
