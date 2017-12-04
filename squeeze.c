/* Exercise 2-4: rewrite `squeeze' to delete any of s2 from s1
 * I'll admit: I got the idea to use a `contains' function from
 * stackoverflow
 * Shame on me :P */

#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);
int contains(char s[], int c);

int main(int argc, char **argv)
{
	if (strnlen(argv[1], 1000) > 1000 || strnlen(argv[2], 1) > 1000) {
		printf("%s\n", "error: arguments must be no more than 1000 characters");
		return 1;
	}

	squeeze(argv[1], argv[2]);
	printf("%s\n", argv[1]);
	return 0;
}

/* squeeze:  delete all s2 from s1 */
void squeeze(char s1[], char s2[])
{
	int i, j;

	for (i = j = 0; s1[i] != '\0'; ++i) {
		if (!contains(s2, s1[i])) {
			s1[j++] = s1[i];
			/* printf("s[%i]%s%c\n", j - 1, " now is ", s1[i]); */
		}
	}
    s1[j] = '\0';
}

/* check if s contains c */
int contains(char s[], int c) {
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == c) {
			/* printf("%s%c%ss[%i]\n", "match! ", s[i], " at ", i); */
			return 1;
		} else {
			++i;
		}
	}

	/* printf("%s\n", "no matches"); */
	return 0;
}