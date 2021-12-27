/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:58:07 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 16:31:22 by maroly           ###   ########.fr       */
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

void	stdincase(t_list s)
{
	char c;

	while (read(0, &c, 1) > 0)
		write(s.p2[1], &c, 1);
	close(s.p2[1]);
}

int	initializing_s(char **av, char **env, t_list s)
{
	int		p1[2];
	int		p2[2];
	int		check;

	check = 0;
	s.i = 1;
	if (ft_strcmp(av[1], "here_doc") == 0)
		s.i += bonushere_doc(av[2]);
	if (pipe(p1) == -1 || pipe(p2) == -1)
		return (ft_putstr(strerror(errno), 2));
	s.p1 = p1;
	s.p2 = p2;
	if (ft_strcmp(av[1], "here_doc") != 0 && ft_strcmp(av[s.ac - 1], "/dev/stdout") != 0 && access(av[s.ac - 1], F_OK) == 0)
		unlink(av[s.ac - 1]);
	if (ft_strcmp(av[1], "/dev/stdin") == 1)
		s.fd = open(av[1], O_RDONLY);
	else
		stdincase(s);
	if (s.fd == -1)
		check += ft_putstr(strerror(errno), 2);
	s.fd2 = open(av[s.ac - 1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (s.fd2 == -1)
		check += ft_putstr(strerror(errno), 2);
	if (check > 0)
		return (1);
	startchildprocess(av, env, s);
	close(p1[0]);
	close(p1[1]);
	close(p2[0]);
	close(p2[1]);
	return (0);
}
