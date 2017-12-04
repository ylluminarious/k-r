/* Exercise 2-3: convert string of hex to integers
 *
 * Yes, you could say I'm cheating by using `strtol'
 * but the whole point of this exercise is to learn
 * typecasting, not to learn integer parsing */

#include <stdio.h>
#include <stdlib.h>

int htoi(char str[]);

int main(int argc, char **argv)
{
	printf("%i\n", htoi(argv[1]));
	return 0;
}

int htoi(char str[])
{
	return (int)(strtol(str, NULL, 16));
}