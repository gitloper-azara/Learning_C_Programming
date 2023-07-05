#include <unistd.h>

void print_char(char c)
{
	write(1, &c, 1);
}

void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		print_char(c);
	}
}

int main(void)
{
	print_alphabet();
	print_char('\n');
	return (0);
}
