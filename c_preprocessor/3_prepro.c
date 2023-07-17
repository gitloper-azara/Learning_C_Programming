#include <stdio.h>
#define PI (22/7.0)
#define SQR(X) ((X) * (X))

int main(void)
{
	double area_circle = PI * 10 * 10;
	printf("Area of a circle = %lf\n", area_circle);

	int n = SQR(10);
	printf("%d\n", n);

	return (0);
}
