#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t i;
	int sign;
	//long long int result;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] >= 9 && nptr[i] <= 13)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10  + nptr[i] - 48;
		i++;
	}
	/*if (result > 2147483647)
		return (2147483647);
	else if (result * sign < -2147483648)
		return (-2147483648);*/
	return (result * sign);
}

int main(int ac, char **av)
{
	printf("Ma fonction    : %d\n", ft_atoi(av[1]));
	printf("Vraie fonction : %d\n", atoi(av[1]));
}
