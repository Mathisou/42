#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *str;
	unsigned char *str2;

	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str[i] && str2[i] && i < n)
	{
		if (str[i] < str2[i])
			return (-1);
		else if (str[i] > str2[i] && i < n)
			return (1);
		i++;
	}
	if (str[i] < str2[i] && i < n)
		return (-1);
	else if (str[i] > str2[i] && i < n)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i;

	i = 0;
	while (i < 20)
	{
		printf("\n     i = %d\n", i);
		printf("Ma fonction :    %d\n", ft_memcmp(av[1], av[2], i));
		printf("vraie fonction : %d\n", memcmp(av[1], av[2], i));
		i++;
	}
}
