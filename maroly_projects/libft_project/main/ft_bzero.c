#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void *ft_bzero(void *s, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = 0;
		i++;
	}
	return (&((char*)s)[i]);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_bzero(av[1], atoi(av[2])));
	//printf("%s\n", bzero(av[1], atoi(av[2])));
}
