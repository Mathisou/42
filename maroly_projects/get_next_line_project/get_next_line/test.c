/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:20:45 by maroly            #+#    #+#             */
/*   Updated: 2021/10/23 13:40:40 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*char	*ft_strdup(char *buffer)
{
	char	*dest;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	dest = malloc(sizeof(*buffer) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (buffer[i])
	{
		dest[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		dest[i] = '\n';
	else
		dest[i] = '\0';
	return (dest);
}*/
char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n' && src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	if (src[i] == '\n')
		dest[i] = '\n';
	//else if (src[i] == '\0')
	else
		dest[i] = '\0';
	return (dest);
}


char *get_next_line(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	int i;
	char *str;

	buffer = NULL;
	i = read(fd, buffer, BUFFER_SIZE);
	buffer[i] = 0;
	//printf("%s\n\n\n\n\n", buffer);
	i = 0;
	while (buffer[i] && buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	//printf("i = %d\n", i);
	//printf("%d\n", i);
	str = malloc(sizeof(*str) * (i + 1));
	//printf("/////////\n%s\n///////\n", buffer);
	//str = ft_strdup(buffer);
	ft_strcpy(str, buffer);
	if (*str == 0)
	{
		//printf("test\n");
		str = NULL;
	}
	return (str);
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
	//printf("%d\n", i);
}

