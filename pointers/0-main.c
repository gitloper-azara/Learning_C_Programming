#include <stdio.h>

/**
 * main - using sizeof to dynamically determine the size of types char,
 * int, and float
 * Return: Always 0
 */

int main(void)
{
	int n;
	double m;
	float a;
	char c;

	printf("Size of type 'char' on my computer: %lu bytes\n", sizeof(char));
	printf("Size of type 'int' on my computer: %lu bytes\n", sizeof(int));
	printf("Size of type 'float' on my computer: %lu bytes\n",
	       sizeof(float));
	printf("Size of type 'double' on my computer: %lu bytes\n",
	       sizeof (double));
	printf("Size of type of my variable n on my computer: %lu bytes\n",
	       sizeof(n));
	printf("Size of type of my variable m on my computer: %lu bytes\n",
	       sizeof(m));
	printf("Size of type of my variable a on my computer: %lu bytes\n",
	       sizeof(a));
	printf("Size of type of my variable c on my computer: %lu bytes\n",
	       sizeof(c));

	return (0);
}
