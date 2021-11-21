#include "libft.h"

int ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int main(int ac, char **av)
{
	int i = 0;
	while (av[1][i])
	{
		printf("%c", ft_toupper(av[1][i]));
		i++;
	}
}
