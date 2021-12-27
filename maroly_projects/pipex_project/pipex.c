/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:54:48 by maroly            #+#    #+#             */
/*   Updated: 2021/12/27 16:32:27 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	firstchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	close(s.p1[0]);
	if (((s.nbarg == 2 && s.i == 1) && s.check == 0)
	|| (s.nbarg == 3 && s.i == 2))
		if (dup2(s.fd, 0) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.fd);
	if (((s.nbarg > 2 || s.check > 0) && s.i == 1) || (s.nbarg > 3 && s.i == 2))
		if (dup2(s.p2[0], 0) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.p2[0]);
	if (s.nbarg < s.ac - 2)
		if (dup2(s.p1[1], 1) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.p1[1]);
	if (s.nbarg == s.ac - 2)
		if (dup2(s.fd2, 1) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.fd2);
	if (execve(s.path, s.newargv, env) == -1)
		ft_putstr(strerror(errno), 2);
	return (0);
}

int	secondchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	close(s.fd);
	close(s.p2[0]);
	if (dup2(s.p1[0], 0) == -1)
		ft_putstr(strerror(errno), 2);
	close(s.p1[0]);
	if (s.nbarg < s.ac - 2)
		if (dup2(s.p2[1], 1) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.p2[1]);
	if (s.nbarg == s.ac - 2)
		if (dup2(s.fd2, 1) == -1)
			ft_putstr(strerror(errno), 2);
	close(s.fd2);
	if (execve(s.path, s.newargv, env) == -1)
		ft_putstr(strerror(errno), 2);
	return (0);
}

void	opening_child(char **av, char **env, t_list s, int sign)
{
	if (sign == 1)
	{
		if (pipe(s.p1) == -1)
			ft_putstr(strerror(errno), 2);
		close(s.p2[1]);
		s.child = fork();
		if (s.child < 0)
			ft_putstr(strerror(errno), 2);
		if (s.child == 0)
			exit(firstchild(av, env, s));
	}
	else
	{
		if (pipe(s.p2) == -1)
			ft_putstr(strerror(errno), 2);
		close(s.p1[1]);
		s.child = fork();
		if (s.child < 0)
			ft_putstr(strerror(errno), 2);
		if (s.child == 0)
			exit(secondchild(av, env, s));
	}
}

void	startchildprocess(char **av, char **env, t_list s)
{
	s.nbarg = s.i;
	while (++(s.nbarg) < s.ac - 1)
	{
		if ((s.nbarg % 2 == 0 && s.i == 1) || (s.nbarg % 2 != 0 && s.i == 2))
		{
			close(s.p1[1]);
			opening_child(av, env, s, 1);
		}
		else
		{
			close(s.p2[1]);
			opening_child(av, env, s, 2);
		}
	}
	close(s.p1[0]);
	close(s.p2[0]);
	close(s.fd);
	close(s.fd2);
}

int	main(int ac, char **av, char **env)
{
	t_list	s;

	if (ac < 5)
		return (1);
	s.ac = ac;
	s.check = 0;
	if (ft_strcmp(av[1], "/dev/stdin") == 0)
		s.check = 1;
	if (initializing_s(av, env, s) > 0)
	{
		//if (s.fd != -1)
		//	close(s.fd);
		//if (s.fd2 != -1)
		//	close(s.fd2);
		return (2);
	}
	if (ft_strcmp(av[1], "here_doc") == 0)
		if (unlink("here_doc") == -1)
			ft_putstr(strerror(errno), 2);
	return (0);
}
