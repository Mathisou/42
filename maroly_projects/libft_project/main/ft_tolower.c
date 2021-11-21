#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

int main(int ac, char **av)
{
	int i = 0;
	while (av[1][i])
	{
		printf("%c", ft_tolower(av[1][i]));
		i++;
	}
}
