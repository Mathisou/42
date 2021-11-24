#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j])
			{
				j++;
                if (i + j > len)
                    return (NULL);
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
	printf("Ma fonction : %s\n", ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15));
	//printf("Vraie fonction       : %s\n", strstr(av[1], av[2]));
}
