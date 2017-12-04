// Exercises 1-6 and 1-7

#include <stdio.h>
/* copy input to output; 2nd version  */
main()
{
	 int c;
	 while ((c = getchar()) != EOF) {
		  putchar(c);

		  // Don't print newline here if `c' is NL or CR
		  if (c != 0x0a && c != 0x0d) {
			   printf("%s\n", "");
		  }
		  printf("%s", "Does char equal EOF?: ");
		  printf("%i\n", c == EOF);
	 }

	 printf("%s\n", "EOF detected (value shown below): ");
	 printf("%i\n", EOF);
}