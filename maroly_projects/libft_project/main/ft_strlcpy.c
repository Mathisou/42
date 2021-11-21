
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_strlcpy(av[1], av[2], atoi(av[3])));
	//printf("%lu", strlcpy(av[1], av[2], atoi(av[3])));
}
