#include <stdio.h>

int main(void)
{
	long x;
	long y;

	printf("Insert the value of x: ");
	scanf("%ld", &x);
	printf("Insert the value of y: ");
	scanf("%ld", &y);

	float z = (float) x / (float) y;
	printf("%f\n", z);
}
