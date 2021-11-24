/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:19:18 by maroly            #+#    #+#             */
/*   Updated: 2021/11/24 12:37:34 by maroly           ###   ########.fr       */
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
    else if (!lst || !f)
        return (NULL);
    else
    {
	    while (lst)
	    {
		    new_lst->content = f(lst->content);
	        del(lst->content);
		    new_lst = new_lst->next;
		    lst = lst->next;
	    }
    }
	return (new_lst);
}
