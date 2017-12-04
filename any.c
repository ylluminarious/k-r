/* Exercise 2-5: write `any' to return the first location in s1
 * where any char from s2 occurs, or -1 if s1 contains no such
 * chars */

#include <stdio.h>
#include <string.h>

int any(char s1[], char s2[]);
int contains(char s[], int c);

int main(int argc, char **argv)
{
	int location;

	if (strnlen(argv[1], 1000) > 1000 || strnlen(argv[2], 1) > 1000) {
		printf("%s\n", "error: arguments must be no more than 100 characters");
		return 1;
	}

	location = any(argv[1], argv[2]);

	if (location != -1) {
		printf("%i\n", location);
	} else {
		printf("%s\n", "no matching chars");
	}

	return 0;
}

/* check if s1 contains any s2 */
int any(char s1[], char s2[])
{
	int i;

	for (i = 0; s1[i] != '\0'; ++i) {
		if (contains(s2, s1[i])) {
			return i;
		}
	}

	return -1;
}

/* check if s contains c */
int contains(char s[], int c) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == c) {
			return 1;
		} else {
			++i;
		}
	}

	return 0;
}