#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

int main(int ac, char **av)
{
	printf("ma fonction :    %s\n", ft_strchr(av[1], atoi(av[2])));
	printf("vraie fonction : %s\n", strchr(av[1], atoi(av[2])));
}
