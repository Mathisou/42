/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonushere_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:38:27 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 16:32:36 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s)
{
	char	*new;
	size_t	size;
	size_t	i;

	i = 0;
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

int	check_line(char *line, char *limiter)
{
	int	j;
	int	size;

	if (!line)
		return (0);
	j = 0;
	size = ft_strlen(line) - 1;
	while (size > 0 && line[size - 1] != '\n')
		size--;
	while (limiter[j] && line[size + j] == limiter[j])
	{
		j++;
		if (limiter[j] == '\0' && line[size + j] == '\n')
			return (j);
	}
	return (0);
}

char	*ft_strcat2(char *dest, const char *src)
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
		new = ft_strcat2(new, (char *)s1);
		free((char *)s1);
		return (ft_strcat2(new, (char *)s2));
	}
}

int	bonushere_doc(char *limiter)
{
	int		fd;
	char	buffer[2];
	char	*line;

	line = NULL;
	while (read(0, buffer, 1) != 0)
	{
		buffer[1] = '\0';
		line = ft_strjoin(line, buffer);
		if (check_line(line, limiter) > 0)
		{
			line[ft_strlen(line) - check_line(line, limiter) - 1] = '\0';
			break ;
		}
	}
	fd = open("here_doc", O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		return (ft_putstr(strerror(errno), 2));
	ft_putstr(line, fd);
	close(fd);
	free(line);
	return (1);
}
