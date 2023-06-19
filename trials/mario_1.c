#include <stdio.h>

int main(void)
{
	int n;
	printf("Input no. of hashes: ");
	scanf("%d", &n);

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
		{
			printf("#");
		}
		printf("\n");
	}
}
