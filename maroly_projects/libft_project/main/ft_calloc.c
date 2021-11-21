#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *tab;
	
	tab = NULL;
	tab = (unsigned char *) malloc(sizeof(*tab) * (nmemb * size));
	if (tab == NULL)
		return (NULL);
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}

int main(int ac, char **av)
{
	int nmemb;
	int size;

	(void)ac;
	nmemb = atoi(av[1]);
	size = atoi(av[2]);
	printf("%s\n", ft_calloc(nmemb, size));
	printf("%s\n", calloc(nmemb, size));
}
