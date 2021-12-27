/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:51:29 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 15:45:09 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stddef.h>
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <libgen.h>

typedef struct s_list
{
	int		nbarg;
	int		ac;
	int		*p1;
	int		*p2;
	int		fd;
	int		fd2;
	int		i;
	int		child;
	char	*path;
	char	**newargv;
	int		check;
}	t_list;

char	*ft_strstr(char *s1, char *s2);
char	*ft_strcat(char *dest, char *src);
char	**putsep(char **path);
char	*findpath(char **av, char **env, int index);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		bonushere_doc(char *limiter);
int		ft_putstr(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
int		ft_putstr(char *s, int fd);
int		initializing_s(char **av, char **env, t_list s);
void	startchildprocess(char **av, char **env, t_list s);
char	**ft_split(char const *s, char c);
char	**destroy_tab(char **tab);
char	*ft_strdup(char *s);

#endif