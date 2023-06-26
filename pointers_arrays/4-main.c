#include <stdio.h>

/**
 * main - storing the address of a variable into a pointer
 * Return: Always 0
 */

int main(void)
{
	int n = 98;
	int *p = &n;

	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p);

	return (0);
}
