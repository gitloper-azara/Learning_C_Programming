#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, *p;

	printf("Enter total no. of values: ");
	scanf("%d", &n);

	p = (int *)malloc(n * sizeof(int));

	printf("Enter values: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", (p + i));
	}
	printf("The entered values are: ");
	for (i =0; i < n; i++)
	{
		printf("%d", *(p + i));
	}
	printf("\n");
	free(p);

	return (0);
}
