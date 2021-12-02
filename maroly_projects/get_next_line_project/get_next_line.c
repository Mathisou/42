/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:26:11 by maroly            #+#    #+#             */
/*   Updated: 2021/12/02 19:01:35 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	//if (s[0] == '\n')
	//	return (1);
	while (s[i])
		i++;
	return (i);

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
	size_t	size;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = NULL;
	new = (char *) malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	new = ft_strcat(new, (char *)s1);
	new = ft_strcat(new, (char *)s2);
	return (new);
}

int	check_buffer(char *s)
{
	int i;

	i = 0;
	if (!s)
	 return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	static char *stock;
	char buffer[BUFFER_SIZE + 1];
	char *new_line;
	int read_output;
	int i;

	i = 0;
	new_line = malloc(sizeof(*new_line) * 1);
	*new_line = '\0';
	if (!stock)
		stock = malloc(sizeof(*stock) * (BUFFER_SIZE + 1));
	else if (stock)
		new_line = ft_strdup(stock);
	while (check_buffer(new_line) == 0 && (read_output = read(fd, &buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_output] = '\0';
		//free(new_line);
		new_line = ft_strjoin(new_line, buffer);
	}
	if (read_output == -1)
		return (NULL);
	while (new_line[i] && new_line[i] != '\n')
		i++;
	stock = split(&new_line[++i], stock);
	stock[read_output] = '\0';
	new_line[i] = '\0';
	return (value_to_return(new_line, stock));
}

/*int main()
{
	int i = 0;
	int fd = open("bible.txt", O_RDONLY);
	char *str;
	//while ((str = get_next_line(fd)) != NULL)
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		i++;
		free(str);
	}
	//printf("%d\n", i);
}*/
