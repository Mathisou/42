#include "libft.h"

int is_power_of_2(int nb)
{
	int i;
	int b;

	i = 2;
	b = 2;
	while (i <= nb)
	{
		if (i == nb)
			return (1);
		i = i * b;
	}
	return (0);
}

int main(int ac, char **av)
{
	(void ) ac;
	printf("%d\n", is_power_of_2(atoi(av[1])));
}
