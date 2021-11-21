#include "libft.h"

char *ft_strdup(const char *s)
{
	char *new;
	size_t size;
	size_t i;

	i = 0;
	new = NULL;
	size = ft_strlen(s);
	new = (char *) malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int main(int ac, char **av)
{
	char *str = av[1];
	char *verif;

	verif = ft_strdup(str);
	int i;
	i = 0;

	/*while (verif[i - 1])
	{
		if (verif[i] != str[i])
			printf("verif[i] = %c et str[i] = %c\n", verif[i], str[i]);
		i++;
	}*/
	printf("str   = %s\n", str);
	printf("verif = %s\n", verif);
	if (strcmp(str, verif) != 0)
	{
		printf("chelou\n");
		return (0);
	}
	else
		printf("nice");
	//printf("Ma fonction :    %s\n", ft_strdup(av[1]));
	//printf("Vraie fonction : %s\n", strdup(av[1]));
}
