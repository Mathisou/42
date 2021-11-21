#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1024);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	while (i <= 255)
	{
		printf("mine = %d\n", ft_isalpha(i));
		printf("real = %d\n", isalpha(i));
		i++;
	}
}
