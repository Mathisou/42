/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:26:11 by maroly            #+#    #+#             */
/*   Updated: 2022/01/28 15:30:55 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	check_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i])
	{
		dest[size + i] = (char)src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	else
	{
		new = malloc(sizeof(*new) * (ft_strlen(s2) + ft_strlen(s1) + 1));
		if (!new)
			return (NULL);
		new[0] = '\0';
		new = ft_strcat(new, (char *)s1);
		free((char *)s1);
		return (ft_strcat(new, (char *)s2));
	}
}

char	*get_next_line2(int fd, char *stock, char *buffer, char *new_line)
{
	int	read_output;
	int	i;

	i = 0;
	read_output = 1;
	while (check_newline(new_line) == 0 && read_output > 0)
	{
		read_output = read(fd, buffer, BUFFER_SIZE);
		if (read_output == 0 && check_newline(stock) == 0)
		{
			*stock = '\0';
			return (value_to_return(new_line, buffer, 0));
		}
		if (read_output == -1)
			return (value_to_return(new_line, buffer, 0));
		buffer[read_output] = '\0';
		new_line = ft_strjoin(new_line, buffer);
	}
	while (new_line[i] && new_line[i] != '\n')
		i++;
	if (new_line[i] == '\n')
		stock = split(&new_line[++i], stock);
	new_line[i] = '\0';
	return (value_to_return(new_line, buffer, 0));
}

char	*get_next_line(int fd)
{
	static char	*stock = 0;
	char		*new_line;
	char		*buffer;

	new_line = 0;
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (value_to_return(new_line, buffer, -1));
	if (!stock)
	{
		stock = malloc((BUFFER_SIZE + 1) * sizeof(*stock));
		stock[0] = '\0';
		if (!stock)
			return (value_to_return(new_line, buffer, -1));
	}
	if (stock && ft_strlen(stock) > 0)
		new_line = ft_strdup(stock);
	return (get_next_line2(fd, stock, buffer, new_line));
}
