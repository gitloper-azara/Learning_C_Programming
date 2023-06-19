#include <stdio.h>

int main(void)
{
	char c;

	printf("Do you agree? ");
	scanf("%s", &c);

	if (c == 'y' || c == 'Y')
		printf("Agreed!\n");
	else if (c == 'n' || c == 'N')
		printf("Not agreed.\n");
}
