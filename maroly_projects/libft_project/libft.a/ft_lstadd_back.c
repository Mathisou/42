/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:39 by maroly            #+#    #+#             */
/*   Updated: 2021/11/23 18:11:52 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp_lst;

	tmp_lst = *alst;
    if (tmp_lst == NULL)
    {
        tmp_lst = new;
        *alst = tmp_lst;
    }
    else
    {
	    while (tmp_lst->next != NULL)
		    tmp_lst = tmp_lst->next;
	    tmp_lst->next = new;
	    *alst = tmp_lst;
    }
}
