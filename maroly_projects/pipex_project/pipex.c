/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:54:48 by maroly            #+#    #+#             */
/*   Updated: 2022/01/10 15:22:49 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	firstchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	if (s.path == NULL)
	{
		ft_putstr("Command not found: ", 2);
		ft_putstr(av[s.nbarg], 2);
		write(2, "\n", 1);
	}
	if ((s.nbarg == 2 && s.i == 1) || (s.nbarg == 3 && s.i == 2))
		dup2(s.fd, 0);
	close(s.fd);
	if ((s.nbarg > 2 && s.i == 1) || (s.nbarg > 3 && s.i == 2))
		dup2(s.p2[0], 0);
	if (s.nbarg < s.ac - 2)
		dup2(s.p1[1], 1);
	if (s.nbarg == s.ac - 2)
		dup2(s.fd2, 1);
	close_fd(s, 1);
	execve(s.path, s.newargv, env);
	return (1);
}

int	secondchild(char **av, char **env, t_list s)
{
	s.path = findpath(av, env, s.nbarg);
	s.newargv = ft_split(av[s.nbarg], ' ');
	if (s.path == NULL)
	{
		ft_putstr("Command not found: ", 2);
		ft_putstr(av[s.nbarg], 2);
		write(2, "\n", 1);
	}
	close(s.fd);
	dup2(s.p1[0], 0);
	if (s.nbarg < s.ac - 2)
		dup2(s.p2[1], 1);
	if (s.nbarg == s.ac - 2)
		dup2(s.fd2, 1);
	close_fd(s, 1);
	execve(s.path, s.newargv, env);
	return (1);
}

void	opening_child(char **av, char **env, t_list s, int sign)
{
	if (sign == 1)
	{
		s.child = fork();
		if (s.child < 0)
			perror("Fork failed");
		if (s.child == 0)
			exit(firstchild(av, env, s));
		close(s.p1[1]);
	}
	else
	{
		s.child = fork();
		if (s.child < 0)
			perror("Fork failed");
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
			pipe(s.p1);
			opening_child(av, env, s, 1);
		}
		else
		{
			pipe(s.p2);
			opening_child(av, env, s, 2);
		}
	}
	wait(NULL);
	close_fd(s, 1);
}

int	main(int ac, char **av, char **env)
{
	t_list	s;

	if (ac < 5)
	{
		ft_putstr("Too few arguments!\n", 2);
		return (1);
	}
	s.ac = ac;
	s.error = 0;
	if (initializing_s(av, env, s) > 0)
		return (2);
	if (ft_strcmp(av[1], "here_doc") == 0)
		unlink("here_doc");
	return (0);
}
