/* Exercise 2-6: write `setbits' function which is analagous to `getbits' */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	printf("%o", setbits(0356, 6, 5, 0335));
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
/*
  I originally envisioned an algo in which you shift the leftmost bits out,
  and then you somehow set the remaining bits...unfortunately shifting is
  different per CPU and I'm not sure how I would have set the bits now that
  I think of it anyway
*/

/*
get the undesired bits of x
shift them by p+1-n
XOR that value with x
(this zeroes out the undesired bits from x)
get the desired bits from y
also shift them by p+1-n
IOR the two values together
this gives x with those y bits turned on
*/
	return ((getbits(x, p, n) << (p+1-n) ^ x) | getbits(y, p, n) << (p+1-n));
}