#include "libft.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)())
{
	t_list *tmp1;
	t_list *tmp2;

	tmp1 = *begin_list;
	while (tmp1 && cmp(tmp1->content, data_ref) == 0)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
	while(tmp1 && tmp1->next)
	{
		if (cmp(tmp1->next->content, data_ref) == 0)
		{
			tmp2 = tmp1->next;
			tmp1->next = tmp1->next->next;
			free(tmp2);
		}
		if (tmp1->next)
			tmp1 = tmp1->next;
	}
	while (*begin_list)
	{
		printf("%s\n", (*begin_list)->content);
		*begin_list = (*begin_list)->next;
	}
}

int tmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	t_list *a;
	t_list *b;
	t_list *c;
	t_list *new;

	a = malloc(sizeof(t_list));
	b = malloc(sizeof(t_list));
	c = malloc(sizeof(t_list));
	new = malloc(sizeof(t_list));

	a->content = "a";
	b->content = "e";
	c->content = "c";
	new->content = "b";

	a->next = b;
	b->next = c;
	c->next = new;
	new->next = NULL;

	ft_list_remove_if(&a, "b", &tmp);
}

