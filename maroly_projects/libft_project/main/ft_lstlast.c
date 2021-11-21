#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
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

	a->content = "everyone ";
	b->content = "how ";
	c->content = "are you ?";
	new->content = "Hello ";

	a->next = b;
	b->next = c;
	c->next = new;
	new->next = NULL;

	a = ft_lstlast(a);
	printf("%s\n", a->content);
}
