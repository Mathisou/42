#include "libft.h"

int	check_string(char const c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*count_size(char const *s1, char const *set)
{
	size_t i;
	size_t size;
	char *new;

	i = 0;
	size = 0;
	new = NULL;
	while (s1[i])
	{
		if (check_string(s1[i], set) == 1)
			size++;
		i++;
	}
	new = (char *) malloc(sizeof(*new) * size);
	if (new == NULL)
		return (NULL);
	return (new);

}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t i;
	size_t j;
	char *new;

	i = 0;
	j = 0;
	new = count_size(s1, set);
	while (s1[i])
	{
		if (check_string(s1[i], set) == 1)
		{
			new[j] = s1[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_strtrim(av[1], av[2]));
}
