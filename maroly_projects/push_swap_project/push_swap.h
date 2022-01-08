/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:14:30 by maroly            #+#    #+#             */
/*   Updated: 2022/01/08 13:44:47 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_lst
{
	int				nb;
	int				pos;
	int				to_top_here;
	int				to_top_link;
	int				link_pos;
	int				nb_link;
	int				nb_mvt;
	struct s_lst	*next;
}	t_lst;

typedef struct s_var
{
	int		posmin;
	int		posmax;
	int		posfirst;
	int		poslast;
	int		stockmax;
	int		stockmin;
	t_lst	*tmp;
	t_lst	*tmp2;
	int		size;
	int		point;
}	t_var;

typedef struct s_varbns
{
	int		count;
	char	*buffer;
	char	*new;
	char	**tab;
}	t_varbns;

char	**destroy_tab(char **tab);
void	sx(t_lst **pile, int sign);
void	rrx(t_lst **pile);
void	rx(t_lst **pile);
void	call_rx(t_lst **pile_a, t_lst **pile_b, int sign);
void	call_rrx(t_lst **pile_a, t_lst **pile_b, int sign);
void	px(t_lst **pile_from, t_lst **pile_to, int sign);
int		print_error(void);
int		ft_strcmp(char *s1, char *s2);
int		check_only_number(char **tab);
int		check_arg(char **tab);
int		check_first_arg(char *str);
t_lst	*new_elem(int nb, int pos);
void	lst_add_back(t_lst **pile_a, int nb, int pos);
int		initializing_pile(t_lst **pile_a, char **tab, int sign);
void	clear_lst(t_lst **pile);
void	lst_add_front(t_lst **pile, t_lst *new);
int		lst_size(t_lst **pile);
void	put_pos(t_lst **pile_a);
void	end_algo(t_lst **pile_a, t_lst **pile_b);
void	find_best_movement(t_lst **pile_a, t_lst **pile_b, t_var *s);
int		check_pile(t_lst **pile_a);
int		is_under_point(t_lst **pile, int point);
char	**sort_tab(char **tab);
int		find_point(int size, t_lst **pile, int sign);
void	algo_above10(t_lst **pile_a, t_lst **pile_b);
void	algo_10_and_under(t_lst **pile_a, t_lst **pile_b);
int		pre_init_pile(t_lst **pile_a, char **av, int ac);
int		ft_putstr(char *str);
char	**init_tab(t_varbns *s);
int		check_tab(char **tab);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *dest, const char *src);

#endif
