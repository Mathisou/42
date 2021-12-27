/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:50:40 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 16:32:44 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strstr(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		if (i == 0)
		{
			while (s1[i + j] == s2[j])
			{
				j++;
				if (s2[j] == '\0')
					return (&s1[i + j]);
			}
		}
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(*new) * (ft_strlen(dest) + ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	while (dest[i])
	{
		new[i] = dest[i];
		i++;
	}
	while (src[j] && src[j] != ' ')
	{
		new[i + j] = src[j];
		j++;
	}
	new[i + j] = '\0';
	free(dest);
	return (new);
}

char	**putsep(char **path)
{
	int	i;
	int	size;

	i = 0;
	while (path[i])
	{
		size = ft_strlen(path[i]);
		path[i][size++] = '/';
		path[i++][size] = '\0';
	}
	return (path);
}

char	*findpath(char **av, char **env, int index)
{
	int		i;
	int		j;
	char	**path;
	char	*new;

	i = 0;
	j = -1;
	while (ft_strstr(env[i], "PATH=") == NULL)
		i++;
	path = ft_split(ft_strstr(env[i], "PATH="), ':');
	putsep(path);
	while (path[++j] != NULL)
		path[j] = ft_strcat(path[j], av[index]);
	j = 0;
	while (path[j] && access(path[j], X_OK) == -1)
		j++;
	new = ft_strdup(path[j]);
	destroy_tab(path);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}
