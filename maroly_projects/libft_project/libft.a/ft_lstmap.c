/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:19:18 by maroly            #+#    #+#             */
/*   Updated: 2021/11/25 15:26:17 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	if (!f || !lst)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new_elem = ft_lstnew(NULL);
		new_elem->content = f(lst->content);
		if (!new_elem)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		lst = lst->next;
	}
	return (new_lst);
}

/*void	*f(void *content)
{
	int i;
	char *s;

	i = 0;
	s = (char *)content;
	while (s[i])
	{
		s[i] = 'y';
		i++;
	}
	return ((void *)s);
}

void	del(void *content)
{
	free(content);
}

int main()
{
	t_list *l;
	t_list *new_lst;

	//l = malloc(sizeof(*l) * 3);
	l->content = "hello";
	//l->next = malloc(sizeof(*l));
	l->next->content = "you";
	//l->next->next = malloc(sizeof(*l));
	l->next->next->content = "!";
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *d;
	t_list *new_lst;

	//a = malloc(sizeof(t_list));
	//b = malloc(sizeof(t_list));
	//c = malloc(sizeof(t_list));
	//d = malloc(sizeof(t_list));
	
	a->content = "everyone ";
	b->content = "how ";
	c->content = "are you ?";
	d->content = "Hello ";

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;

	new_lst = ft_lstmap(a, &f, &del);
	while (new_lst)
	{
		printf("%s\n", new_lst->content);
		new_lst = new_lst->next;
	}
}*/
