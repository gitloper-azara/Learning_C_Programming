#include <stdio.h>

int main()
{
	int age;

	printf("Please input your age:\n");
	scanf("%d", &age);

	if (age < 100) {
		printf("You are pretty young!\n");

	} else if (age == 100) {
		printf("You are old!\n");

	} else if (age > 100) {
		printf("You are really old\n");
	}

	return 0;
}
