/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:58:07 by maroly            #+#    #+#             */
/*   Updated: 2021/12/29 13:56:42 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putstr(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	if (fd == 2)
		write(fd, "\n", 1);
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	stdincase(t_list s, char **av)
{
	char	c;
	int		i;
	int		j;
	char	*str;

	i = 2;
	j = 0;
	str = "ls";
	while (i < s.ac)
	{
		while (av[i][j] == str[j])
		{
			j++;
			if (j == 2)
				return ;
		}
		i++;
		j = 0;
	}
	while (read(0, &c, 1) > 0)
		write(s.p2[1], &c, 1);
}

t_list	initializing_s2(char **av, t_list s)
{
	if (ft_strcmp(av[1], "here_doc") != 0
		&& ft_strcmp(av[s.ac - 1], "/dev/stdout") != 0
		&& access(av[s.ac - 1], F_OK) == 0)
		unlink(av[s.ac - 1]);
	if (s.check == 0)
	{
		s.fd = open(av[1], O_RDONLY);
		if (s.fd == -1)
			s.error += ft_putstr(strerror(errno), 2);
	}
	else
		stdincase(s, av);
	s.fd2 = open(av[s.ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (s.fd2 == -1)
		s.error += ft_putstr(strerror(errno), 2);
	return (s);
}

int	initializing_s(char **av, char **env, t_list s)
{
	int		p1[2];
	int		p2[2];

	s.i = 1;
	if (ft_strcmp(av[1], "here_doc") == 0)
		s.i += bonushere_doc(av[2]);
	if (pipe(p1) == -1 || pipe(p2) == -1)
		s.error += ft_putstr(strerror(errno), 2);
	s.p1 = p1;
	s.p2 = p2;
	s = initializing_s2(av, s);
	if (s.error > 0)
		return (s.error);
	startchildprocess(av, env, s);
	return (0);
}
