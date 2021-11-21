#include "libft.h"

int	count_divide(int n)
{
	int size;

	size = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		size++;
	}
	if (n < 0)
		size++;
	return (size + 1);
}

char *ft_itoa(int n)
{
	int size;
	char *str;

	str = NULL;
	size = count_divide(n);
	printf("%d\n", size);
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str = "-2147483648\0";
			return (str);
		}
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[size - 1] = n % 10 + 48;
		size--;
		n = n / 10;
	}
	str[size - 1] = n + 48;
	return (str);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_itoa(atoi(av[1])));
}
