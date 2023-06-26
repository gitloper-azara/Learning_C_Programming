#include <stdio.h>

/**
 * modif_my_char_var - modifies my char variable
 *
 * Return: nothing
 */

void modif_my_char_var(char *cc, char ccc)
{
	printf("Value of 'c': %p\n", cc);
	printf("Address of 'c': %p\n", &cc);
	printf("Value of 'c': %d\n", ccc);
	printf("Address of 'c': %p\n", &ccc);
	*cc = 'o';
	ccc = 'l';
}

/**
 * main - how to modify the value of a char var outside the function
 *
 * Return: Always 0
 */

int main(void)
{
	char c = 'H';
	char *p;

	p = &c;

	printf("Value of 'c' before the call: %d ('%c')\n", c, c);
	printf("Address of 'c': %p\n", &c);
	printf("Value of 'p': %p\n", p);
	printf("Address of 'p': %p\n", &p);
	modif_my_char_var(p, c);

	printf("Value of 'c' after the call: %d ('%c')\n", c, c);

	return (0);
}
