/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:30:39 by maroly            #+#    #+#             */
/*   Updated: 2021/11/07 12:56:18 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int	i;
	size_t size;

	i = 0;
	new = NULL;
	size = ft_strlen(s);
	new = (char *) malloc(sizeof(*new) * (size + 1));
	if (new == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
	{
		new[i] = s[i];
		//printf("%d\n", s[i]);
		i++;
		//printf("\nstrdup : %d et i = %d", s[i], i);
	}
	//printf("\n");
	printf("%d\n", s[i - 1]);
	if (s[i - 1] == '\0' && i - 1 != -1)
	{
		printf("test1 et i = %d\n", i - 1);
		new[i] = '\0';
	}
	else
	{
		printf("test2 et i = %d\n", i);
		new[i] = '\n';
	}
	//printf("%s\n", new);
	return (new);
}

char *get_next_line(int fd)
{
	int i;
	char *next_line;
	char buffer[BUFFER_SIZE + 1];

	i = 0;
	while (read(fd, &buffer[i], 1) != 0 && (i < BUFFER_SIZE - 1 &&
				(buffer[i] != '\n' && buffer[i] != '\0')))
		i++;
	//printf("%d\n", buffer[i]);
	//printf("\ngnl : %d et i = %d", buffer[i], i);
	next_line = ft_strdup(buffer);
	//printf("\n\n/////////\n\ntest = %s\n\n/////////\n\n", buffer);
	if (*next_line == '\0')
		return (NULL);
	return (next_line);
}

int main()
{
	int i = 0;
	int fd = open("test.txt", O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		i++;
		free(str);
	}
	printf("%d\n", i);
}
