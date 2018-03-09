/* This is like bitcount.c, but uses the inefficient version of `bitcount' to
 * illustrate the difference between the two. This file has a corresponding
 * assembly file under `asm' so that the two algorithms can be more closely
 * inspected and contrasted. */

#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main(int argc, char **argv)
{
	if (argc > 2 || argc == 1) {
		printf("%s", "You need to supply a number to get its bit-count.");
		return 1;
	}

	printf("%i", bitcount(atoi(argv[1])));
	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{

	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;

	return b;
}
