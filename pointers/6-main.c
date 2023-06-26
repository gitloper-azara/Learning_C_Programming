#include <stdio.h>

/**
 * main - dereferencing pointers, example with int and char types
 * Return: Always 0
 */

int main(void)
{
	int n = 98;
	int *p;
	char c = 72;
	char *pp;

	p = &n;
	pp = &c;

	printf("Value of 'c': %d ('%c')\n", c, c);
	printf("Address of 'c': %p\n", &c);
	printf("Value of 'pp': %p\n", pp);
	printf("Value of 'n': %d\n", n);
	printf("Address of 'n': %p\n", &n);
	printf("Value of 'p': %p\n", p);

	*p = 402;
	*pp = 111;

	printf("Value of 'n': %d\n", n);
	printf("Value of '*pp': %d\n", *pp);
	printf("Value of 'c': %d ('%c')\n", c, c);
	printf("Value of '*pp': %d ('%c')\n", *pp, *pp);

	return (0);
}
