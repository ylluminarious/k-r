#include <stdio.h>

// just to test something stated in K&R...
int main() {
	printf("%s\n", "hello, " "world");

	printf("%s\n", "this "
		   "is "
		   "also "
		   "my "
		   "hello "
		   "to "
		   "the "
		   "world");
}