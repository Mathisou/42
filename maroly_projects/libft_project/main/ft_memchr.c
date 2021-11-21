#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;
	unsigned char *str;

	i = 0;
	str = (unsigned char *)s;
	printf("%s\n", str);
	while (str[i] && i < n)
	{
		printf("str[i] = %d et c = %d\n", str[i], (unsigned char)c);
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	//if (str[i] == c && i < n)
	//	return (&str[i]);
	return (NULL);
}

int main(int ac, char **av)
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};

	printf("ma fonction    :%s\n", (char *)ft_memchr(tab, -1, 7));
	printf("Vraie fonction :%s\n", (char *)memchr(tab, -1, 7));

	//printf("ma fonction    : %s\n", ft_memchr(av[1], atoi(av[2]), atoi(av[3])));
	//printf("vraie fonction : %s\n", memchr(av[1], atoi(av[2]), atoi(av[3])));
}
