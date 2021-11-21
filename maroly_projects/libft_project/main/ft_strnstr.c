#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t stock;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			stock = i;
			while (big[stock] == little[j])
			{
				stock++;
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}

int main(int ac, char **av)
{
	printf("Ma fonction (avec n) : %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
	printf("Vraie fonction       : %s\n", strstr(av[1], av[2]));
}
