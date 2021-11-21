#include "libft.h"

void	ft_sort_list(t_list* lst, int (*cmp)())
{
	t_list *tmp_l;
	t_list *temp2;
	void *swap;

	tmp_l = lst;
	while (tmp_l != NULL)
	{
		temp2 = tmp_l->next;
		while (temp2 != NULL)
		{
			if (cmp(tmp_l->content,temp2->content) == 0)
			{
				swap = tmp_l->content;
				tmp_l->content = temp2->content;
				temp2->content = swap;
			}
			temp2 = temp2->next;
		}
		tmp_l = tmp_l->next;
	}
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] <= s2[i]);
		i++;
	}
	return (s1[i] <= s2[i]);
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

	ft_sort_list(a, &ft_strcmp2);
	while (a)
	{
		printf("%s\n", a->content);
		a = a->next;
	}
}

