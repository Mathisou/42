/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:16:17 by maroly            #+#    #+#             */
/*   Updated: 2021/11/23 18:28:37 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	while (tmp_lst)
	{
		del(tmp_lst->content);
		free(tmp_lst);
		tmp_lst = tmp_lst->next;
	}
	tmp_lst = NULL;
	*lst = tmp_lst;
}
