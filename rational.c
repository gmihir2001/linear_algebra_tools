#include <stdio.h>

#include "rational.h"

// return the gcd of the two number.
int gcd(int a, int b)
{
	if (a == 0 || b == 1) {
		return 1;
	}

	if (a > b){
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
	 int remainder;
	 remainder = a%b;

	 while (remainder !=0){
		a = b;
		b = remainder;
		remainder = a % b;
	 }
	return b;
}

struct rational rational_create(int num, int den) {
	struct rational ret;
	ret.num = num;
	ret.den = den;

	return ret;
}

struct rational rational_add(struct rational a, struct rational b) {
	struct rational result;

	result.num = (a.num * b.den) + (b.num * a.den);

	result.den = a.den * b.den;

	int rational_gcd = gcd(result.num, result.den);

	result.num = result.num / rational_gcd;
	result.den = result.den / rational_gcd;

	return result;
}

struct rational rational_mult(struct rational a, struct rational b) {
	struct rational result;
	result.num = (a.num * b.num);
	result.den = (a.den * b.den);
	int rational_gcd = gcd(result.num, result.den);
	result.num = result.num / rational_gcd;
	result.den = result.den / rational_gcd;
	return result;
}

struct rational rational_subt(struct rational a, struct rational b) {

	struct rational result;
	result.num = (a.num * b.den) - (b.num * a.den);
	result.den = a.den * b.den;
	int rational_gcd = gcd(result.num, result.den);
	result.num = result.num / rational_gcd;
	result.den = result.den / rational_gcd;
	return result;
}

struct rational rational_div(struct rational a, struct rational b) {
	struct rational result;
	result.num = (a.num * b.den);
	result.den = (a.den * b.num);

	int rational_gcd = gcd(result.num, result.den);
	printf("Got the gcd as %d\n", rational_gcd);
	result.num = result.num / rational_gcd;
	result.den = result.den / rational_gcd;
	return result;
}

bool rational_eq(struct rational a, struct rational b) {
	return (a.num == b.num && a.den == b.den);
}

void rational_print(struct rational a) {
	if ( a.den == 1 ) {
		printf("%d\t", a.num);
	} else {
		printf("%d/%d\t", a.num, a.den);
	}
}
