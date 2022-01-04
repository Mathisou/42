/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:14:30 by maroly            #+#    #+#             */
/*   Updated: 2022/01/04 12:31:49 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct nb_list
{
    int nb;
    struct nb_list *next;
}   nb_list;

typedef struct s_struct
{
    int ac;
}   t_struct;

# include "libft/libft.h"

char    **destroy_tab(char **tab);
void    sa(nb_list **pile_a);
void    sb(nb_list **pile_b);
void    ss(nb_list **pile_a, nb_list **pile_b);
void    pa(nb_list **pile_a, nb_list **pile_b);
void    pb(nb_list **pile_a, nb_list **pile_b);
int     print_error();
int     ft_strcmp(char *s1, char *s2);
int     check_only_number(char **tab);
int     check_arg(char **tab);
int     check_first_arg(char *str);
nb_list *new_elem(int nb);
void    lst_add_back(nb_list **pile_a, int nb);
int     initializing_l(nb_list **pile_a, char **tab, int sign);
void    clear_lst(nb_list **pile);
void    lst_add_front(nb_list **pile, nb_list *new);
void    ra(nb_list **pile_a);
void    rb(nb_list **pile_b);
void    rr(nb_list **pile_a, nb_list **pile_b);
void    rra(nb_list **pile_a);
int		lst_size(nb_list **pile);

#endif