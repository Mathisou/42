/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:54:48 by maroly            #+#    #+#             */
/*   Updated: 2021/12/29 13:55:36 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	firstchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	if (((s.nbarg == 2 && s.i == 1) && s.check == 0)
		|| (s.nbarg == 3 && s.i == 2))
		if (dup2(s.fd, 0) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	if (((s.nbarg > 2 || s.check > 0) && s.i == 1) || (s.nbarg > 3 && s.i == 2))
		if (dup2(s.p2[0], 0) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	if (s.nbarg < s.ac - 2)
		if (dup2(s.p1[1], 1) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	if (s.nbarg == s.ac - 2)
		if (dup2(s.fd2, 1) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	close_fd(s, 1);
	if (execve(s.path, s.newargv, env) == -1)
		s.error += ft_putstr(strerror(errno), 2);
	return (0);
}

int	secondchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	if (dup2(s.p1[0], 0) == -1)
		s.error += ft_putstr(strerror(errno), 2);
	if (s.nbarg < s.ac - 2)
		if (dup2(s.p2[1], 1) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	if (s.nbarg == s.ac - 2)
		if (dup2(s.fd2, 1) == -1)
			s.error += ft_putstr(strerror(errno), 2);
	close_fd(s, 1);
	if (execve(s.path, s.newargv, env) == -1)
		s.error += ft_putstr(strerror(errno), 2);
	return (0);
}

void	opening_child(char **av, char **env, t_list s, int sign)
{
	if (sign == 1)
	{
		s.child = fork();
		if (s.child < 0)
			s.error += ft_putstr(strerror(errno), 2);
		if (s.child == 0)
			exit(firstchild(av, env, s));
		close(s.p1[1]);
	}
	else
	{
		s.child = fork();
		if (s.child < 0)
			s.error += ft_putstr(strerror(errno), 2);
		if (s.child == 0)
			exit(secondchild(av, env, s));
		close(s.p2[1]);
	}
}

void	startchildprocess(char **av, char **env, t_list s)
{
	s.nbarg = s.i;
	close_fd(s, 0);
	while (++(s.nbarg) < s.ac - 1)
	{
		if ((s.nbarg % 2 == 0 && s.i == 1) || (s.nbarg % 2 != 0 && s.i == 2))
		{
			if (pipe(s.p1) == -1)
				s.error += ft_putstr(strerror(errno), 2);
			opening_child(av, env, s, 1);
		}
		else
		{
			if (pipe(s.p2) == -1)
				s.error += ft_putstr(strerror(errno), 2);
			opening_child(av, env, s, 2);
		}
	}
	close_fd(s, 1);
}

int	main(int ac, char **av, char **env)
{
	t_list	s;

	if (ac < 5)
		return (1);
	s.ac = ac;
	s.check = 0;
	s.error = 0;
	if (ft_strcmp(av[1], "/dev/stdin") == 0)
		s.check = 1;
	if (initializing_s(av, env, s) > 0)
		return (2);
	if (ft_strcmp(av[1], "here_doc") == 0)
		if (unlink("here_doc") == -1)
			ft_putstr(strerror(errno), 2);
	return (0);
}
