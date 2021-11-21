#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *new;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	new = NULL;
	while (s[i] && i != start)
		i++;
	if (ft_strlen(&s[i]) >= len)
		new = (char *) malloc(sizeof(*new) * len);
	else
		new = (char *) malloc(sizeof(*new) * ft_strlen(&s[i]));
	if (new == NULL)
		return (NULL);
	len += i;
	while (s[i] && i < len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_substr(av[1], atoi(av[2]), atoi(av[3])));
}
