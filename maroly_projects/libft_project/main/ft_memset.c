#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void *ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("Ma fonction = %s\n", (char *)ft_memset("hello", 58, 0));
	printf("Vrai memset = %s\n", (char *)memset("hello", 58, (0)));
	//memset(av[1], atoi(av[2]), atoi(av[3]));
}
