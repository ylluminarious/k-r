/* Exercise 2-1 */

/* Determine sizes of various types by printing from header
 * files and also by underflowing them.
 */

#include <limits.h>
#include <float.h>
#include <stdio.h>

int main()
{
	printf("%s\n\n",   "Limits according to <limits.h>:");
	printf("%s%i\n",    "max number of bits in `char': ", CHAR_BIT);
	printf("%s%i\n",    "max size of `unsigned char':  ", UCHAR_MAX);
	printf("%s%i\n",    "max size of `signed char':    ", SCHAR_MAX);
	printf("%s%i\n\n",  "min size of `signed char':    ", SCHAR_MIN);

	printf("%s%i\n",    "max size of `unsigned short': ", USHRT_MAX);
	printf("%s%i\n",    "max size of `signed short':   ", SHRT_MAX);
	printf("%s%i\n\n",  "min size of `signed short':   ", SHRT_MIN);

	printf("%s%u\n",    "max size of `unsigned int':   ", UINT_MAX);
	printf("%s%i\n",    "max size of `signed int':     ", INT_MAX);
	printf("%s%i\n\n",  "min size of `signed int':     ", INT_MIN);

	printf("%s%i\n",    "max number of bits in `long': ", LONG_BIT);
	printf("%s%lu\n",   "max size of `unsigned long':  ", ULONG_MAX);
	printf("%s%ld\n",   "max size of `signed long':    ", LONG_MAX);
	printf("%s%ld\n\n", "min size of `signed long':    ", LONG_MIN);


	printf("%s\n\n", "Limits according to underflow:");

	/* I'm basically cheating from here on out...
	 * it's easy to get the max size of unsigned
	 * things b/c you just have to make it underflow
	 * by setting it equal to -1. From thereon, you
	 * can just do some nifty division to figure out
	 * everything else */

	int  bit_limit, j = 1;
	unsigned long i = 0;

	unsigned char uc   = -1;
	unsigned char cmax = uc / 2;
	unsigned char cmin = cmax + 1;

	/* In this loop and the following ones like it,
	 * we are essentially computing log2(i) to determine
	 * the bit limit of the given type */

	for (i = uc; i != 0; i = i / 2) {
		bit_limit = j;
		++j;
	}

	j = 1;

	printf("%s%i\n",    "max number of bits in `char':  ", bit_limit);
	printf("%s%i\n",    "max size of `unsigned char':   ", uc);
	printf("%s%i\n",    "max size of `signed char':     ", cmax);
	printf("%s-%i\n\n", "min size of `signed char':     ", cmin);

	unsigned short us   = -1;
	unsigned short smax = us / 2;
	unsigned short smin = smax + 1;

	for (i = us; i != 0; i = i / 2) {
		bit_limit = j;
		++j;
	}

	j = 1;

	printf("%s%i\n",    "max number of bits in `short': ", bit_limit);
	printf("%s%i\n",    "max size of `unsigned short':  ", us);
	printf("%s%i\n",    "max size of `signed short':    ", smax);
	printf("%s-%i\n\n", "min size of `signed short':    ", smin);

	unsigned int ui   = -1;
	unsigned int imax = ui / 2;
	unsigned int imin = imax + 1;

	for (i = ui; i != 0; i = i / 2) {
		bit_limit = j;
		++j;
	}

	j = 1;

	printf("%s%i\n",     "max number of bits in `int':   ", bit_limit);
	printf("%s%u\n",     "max size of `unsigned int':    ", ui);
	printf("%s%u\n",     "max size of `signed int':      ", imax);
	printf("%s-%u\n\n",  "min size of `signed int':      ", imin);

	unsigned long ul   = -1;
	unsigned long lmax = ul / 2;
	unsigned long lmin = lmax + 1;

	for (i = ul; i != 0; i = i / 2) {
		bit_limit = j;
		++j;
	}

	j = 1;

	printf("%s%i\n",      "max number of bits in `long':  ", bit_limit);
	printf("%s%lu\n",     "max size of `unsigned long':   ", ul);
	printf("%s%lu\n",     "max size of `signed long':     ", lmax);
	printf("%s-%lu\n\n",  "min size of `signed long':     ", lmin);
}