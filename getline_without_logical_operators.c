/* Exercise 2-2 */

/* Implement the `getline' function without && or || */

#include <stdio.h>

#define MAX_LINE_LENGTH 1000
int k_and_r_getline(char s[], int lim);

int main()
{
	int  len;                   /* current line length */
	char line[MAX_LINE_LENGTH]; /* current input line */

	while ((len = k_and_r_getline(line, MAX_LINE_LENGTH)) > 0) {
		printf("%s\n", line);
	}

	return 0;
}

int k_and_r_getline(char s[], int lim)
{
	int c, i = 0;

	while (i < lim - 1) {
		if ((c = getchar()) != EOF) {
			if (c != '\n') {
				s[i] = c;
				++i;
			} else {
				s[i] = c;
				++i;
				break;
			}
		}
	}

	s[i] = '\0';
	return i;
}