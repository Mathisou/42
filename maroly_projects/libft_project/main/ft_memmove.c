#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int verification(char *str, int n)
{
	if (n >= ft_strlen(str) / 2)
		return 1;
	return 0;
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (verification(((char *)dest), n) == 1)
	{
		((char *)src)[n] = '\0';
		return (((void *)src));
	}
	else
	{
		if (dest > src)
		{
			while (n > 0)
			{
				((char *)dest)[n - 1] = ((char *)src)[n - 1];
				n--;
			}
		}
		else
		{
			while (i < n)
			{
				((char *)dest)[i] = ((char *)src)[i];
				i++;
			}
		}
	}
	return (dest);
}

int main(int ac, char **av)
{
	int size = 128 * 1024 * 1024;
	char *dst = (char *)malloc(sizeof(char) * size);
	char *data = (char *)malloc(sizeof(char) * size);

	memset(data, 'A', size);
	if (!dst)
	{
		printf("pb\n");
		return 0;
	}
	ft_memmove(dst, data, size);
	printf("ok\n");
	return 0;

//printf("%p\n", ft_memmove("test", NULL, 5));
	//printf("%s\n", memmove(av[1], av[2], atoi(av[3])));
	//printf("%p\n", ft_memmove(av[1], NULL, atoi(av[2])));
	//printf("%p\n", memmove(NULL, av[1], atoi(av[2])));
}
