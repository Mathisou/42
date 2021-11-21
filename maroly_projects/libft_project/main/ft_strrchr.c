#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t size;

	size = ft_strlen(s);
	while (size > 0)
	{
		if (s[size] == c)
			return ((char *)&s[size]);
		size--;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	(void)ac;
	printf("Ma fonction :    %s\n", ft_strrchr(av[1], atoi(av[2])));
	printf("vraie fonction : %s\n", strrchr(av[1], atoi(av[2])));
}
