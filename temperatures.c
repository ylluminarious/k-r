// Modified to do Exercises 1-3 and 1-4

#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
main()
{
	 float fahr, celsius;
	 float lower, upper, step;
	 lower = 0;      /* lower limit of temperatuire scale */
	 upper = 300;    /* upper limit */
	 step = 20;      /* step size */
	 fahr = lower;

	 printf("%6s	", "Celsius");
	 printf("%3s\n", "Fahrenheit");
	 while (fahr <= upper) {
		  celsius = (5.0/9.0) * (fahr-32.0);
		  printf("%6.1f	%3.0f\n", celsius, fahr);
		  fahr = fahr + step;

	 }
}