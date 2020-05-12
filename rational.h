#ifndef RATIONAL_H
#define RATIONAL_H

#include <stdbool.h>

struct rational {

	int num;
	int den;
};

struct rational rational_create(int num, int den);

struct rational rational_add(struct rational a, struct rational b);

struct rational rational_mult(struct rational a, struct rational b);

struct rational rational_subt(struct rational a, struct rational b);

struct rational rational_div(struct rational a, struct rational b);

bool rational_eq(struct rational a, struct rational b);

void rational_print(struct rational a);

#endif
