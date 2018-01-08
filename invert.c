/* Exercise 2-7: write a function which is like `setbits' but for inversion */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);

int main()
{
	printf("%o", invert(0356, 6, 5));
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return ((getbits(x, p, n) << (p+1-n) ^ x) | getbits(y, p, n) << (p+1-n));
}

unsigned invert(unsigned x, int p, int n)
{
	return setbits(x, p, n, ~x);
}