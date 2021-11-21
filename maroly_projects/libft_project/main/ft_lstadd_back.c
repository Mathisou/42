#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp_lst;

	tmp_lst = *alst;
	while (tmp_lst->next != NULL)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = new;
	*alst = tmp_lst->next;
	printf("%s\n", (*alst)->content);
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

	ft_lstadd_back(&a, new);
}

