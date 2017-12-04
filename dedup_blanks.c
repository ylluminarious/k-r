// Exercise 1-9

#include <stdio.h>

main()
{
	 int c;
	 int blank_count;

	 while ((c = getchar()) != EOF) {
		  if (c != 0x20) {
			   putchar(c);
			   blank_count = 0;
		  } else {
			   ++blank_count;
		  }

		  if (blank_count == 1) {
			   printf("%s", " ");
		  }
	 }
}