/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:14:34 by maroly            #+#    #+#             */
/*   Updated: 2021/11/23 17:44:26 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count_divide(long n)
{
	int	size;

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

char	*ft_itoa(int n)
{
	int		size;
	char	*str;
    long    nbr;

	str = NULL;
    nbr = n;
	size = count_divide(nbr);
	/*if (n == -2147483648)
    {
        str = malloc(sizeof(*str) * 12);
        str = "-2147483648\0";
        return (str);
    }
		//return ("-2147483648\0");*/
	str = (char *) malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		str[size - 1] = nbr % 10 + 48;
		size--;
		nbr = nbr / 10;
	}
	str[size - 1] = nbr + 48;
	return (str);
}

int main(int ac, char **av)
{
    (void)ac;
    printf("%s\n", ft_itoa(atoi(av[1])));
}
