#include <stdio.h>

/**
 * main - you cannot modify a
 * the variables we declare as arrays do not hold a memory
 * address. An array is not a pointer.
 *
 * Return: Always 0
 */

int main(void)
{
	int a[5];
	int b;
	int c[5];

	a = 0; /**
		* nop
		*/

	a = &b; /**
		 * nop
		 */

	a = c; /**
		* nop
		*/

	return (0);
}
