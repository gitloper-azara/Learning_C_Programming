#include <stdio.h>

int main(void)
{
	int x;
	int y;
	int z;

	printf("Insert the value of x: ");
	scanf("%d", &x);
	printf("Insert the value of y: ");
	scanf("%d", &y);

	z = x / y;
	printf("%d\n", z);
}
