/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:19:18 by maroly            #+#    #+#             */
/*   Updated: 2021/11/25 13:06:55 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!f) //|| !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		if (!(new_elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	printf("%s\n", new_lst->content);
	return (new_lst);
	/*t_list	*new_lst;
	//t_list	*beginning;

	if (!lst || !f)
		return (NULL);
	//begin = new_lst;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst->content == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_lst = lst->next;
		lst = new_lst;
	}
	printf("%s\n", new_lst->content);
	return (new_lst);*/
}
/*
#include <stdio.h>

static void			ft_delelem(void *content)
{

	free(content);
}

static void		*ft_mapelem(void *content)
{
	int		i;
	char *c;

	c = (char *)content;
	i = 0;

	while (c[i])
	{
		c[i] = 'y';
		i++;
	}
	return (c);
}
*/
int main()
{
	t_list *l = ft_lstnew(strdup(" 1 2 3 "));
	t_list *ret;

	l->next = ft_lstnew(strdup("ss"));
	l->next->next = ft_lstnew(strdup("-_-"));
	ret = ft_lstmap(l, &ft_mapelem, ((void *)0));
	if (!strcmp(ret->content, "OK !") && !strcmp(ret->next->content, "OK !") && !strcmp(ret->next->next->content, "OK !") && !strcmp(l->content, " 1 2 3 ") && !strcmp(l->next->content, "ss") && !strcmp(l->next->next->content, "-_-"))
		printf("succeed\n");
	printf("failed\n");
}


