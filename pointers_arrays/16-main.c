#include <stdio.h>

/**
 * main - An array is not a pointer, but...
 *
 * Return: Always 0
 */

int main(void)
{
	int a[98]; /**
		    * array
		    */
	printf("a: %p\n", a);
	printf("but &a[0] is also: %p\n", &a[0]);

	return (0);
}
