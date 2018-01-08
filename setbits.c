/* Exercise 2-6: write `setbits' function which is analagous to `getbits' */
#include <stdio.h>
#include <limits.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	printf("%o", setbits(0356, 3, 4, 0335));
}

unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
/*
  get the low-end bits of y
  (we have automatically zeroed out the high-end bits thereby)
  get the high-end bits of x
  left-shift those high bits so that they're where y's high-bits were
  IOR the two values together

  I originally envisioned an algo in which you shift the leftmost bits out,
  and then you somehow set the remaining bits...unfortunately shifting is
  different per CPU and it wasn't a very well-thought-out plan anyway
*/
	return (getbits(y, p, n) | (getbits(x, p+n, n) << n));
}