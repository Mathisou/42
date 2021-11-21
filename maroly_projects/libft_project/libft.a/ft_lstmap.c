/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:19:18 by maroly            #+#    #+#             */
/*   Updated: 2021/10/19 12:19:27 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	new_lst = NULL;
	new_lst = malloc(sizeof(t_list) * ft_lstsize(lst));
	if (new_lst == NULL)
		return (NULL);
	while (lst)
	{
		f(lst->content);
		new_lst->content = lst->content;
		del(lst->content);
		new_lst->next = lst->next;
		lst = lst->next;
	}
	lst = NULL;
	return (new_lst);
}
