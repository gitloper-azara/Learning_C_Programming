#include <stdio.h>

int main(void)
{
	int n;
	do
	{
		printf("Input no. of hashes: ");
		scanf("%d", &n);
	}
	while (n < 1);

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			printf("#");
		}
		printf("\n");
	}
}
