// Modified to do exercise 1-19
#include <stdio.h>
#define MAXLINE 1000            /* maximum input line length */

int my_getline(char line[], int maxline);
void reverse(char line[], int len);

main()
{
	 int len;                   /* current line length */
	 char line[MAXLINE];        /* current input line */

	 while ((len = my_getline(line, MAXLINE)) > 0) {
		  reverse(line, len);
		  printf("%s\n", line);
	 }

	 return 0;
}

/* my_getline: read a line into `s', return length */

int my_getline(char s[], int lim)
{
	 int c, i;

	 for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		  s[i] = c;
	 }

	 if (c == '\n') {
		  s[i] = c;
		  ++i;
	 }

	 s[i] = '\0';
	 return i;
}

/* reverse: reverse string character string `line'
 * by swapping the first and last element for half
 * the length of the array - 1 */
void reverse(char line[], int len)
{
	 int i, a, b;
	 int halfway = len / 2;

	 for (i = 0; i < halfway; ++i) {
		  a = line[i];
		  b = line[len - i - 1];

		  line[i]           = b;
		  line[len - i - 1] = a;
	 }
}