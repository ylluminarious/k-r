/* Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the
   rightmost 1-bit in x. Explain why. Use this observation to write a faster
   version of bitcount.
*/

/* Explanation of why the above trick works:
 * 10 in binary is 1010
 * 9 in binary is  1001
 * If you AND these two numbers together, you get 8 which is 1000
 *
 * The reason why subtracting a number by one and ANDing it with that difference
 * produces a number with the rightmost 1-bit gone is because the 1-bit gets
 * moved by one place to the right when you subtract by one. This is just a
 * facet of arithmetic in binary. Then, once you AND the two values together,
 * the difference's 1-bit is in a place where there is a 0 in the original
 * number and vice versa. So you effectively zero out that rightmost 1-bit upon
 * ANDing these values.
 *
 * In order to make bitcount more efficient as K&R suggest, all you have to do
 * is change bitcount so that it repeatedly performs this operation until there
 * are no more 1-bits remaining and you just count for every iteration that you
 * had to do that.
 *
 * This way, you eliminate the need for extra jumping / branching in the program
 * because you just perform this operation again and again until you hit zero.
*/

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
	int bits = 0;

	while (x != 0) {
		x &= (x - 1);
		bits++;
	}

	return bits;
}
