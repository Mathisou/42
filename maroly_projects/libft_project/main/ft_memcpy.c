#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_memcpy(av[1], av[2], atoi(av[3])));
	//printf("%s\n", memcpy(av[1], av[2], atoi(av[3])));
}
