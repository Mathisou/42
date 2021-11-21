#include "libft.h"

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = *alst;
		*alst = new;
	}
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
	c->next = NULL;
	new->next = NULL;

	ft_lstadd_front(&a, new);

	while (a)
	{
		printf("%s\n", a->content);
		a = a->next;
	}
}
