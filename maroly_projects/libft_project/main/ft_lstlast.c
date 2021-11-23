#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    /*if (lst == NULL)
        return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);*/
    while (lst)
    {
        if (!lst->next)
            return(lst);
        lst = lst->next;
    }
    return (lst);
}

int main()
{
/*	t_list *a;
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
	printf("%s\n", a->content);*/

 	t_list *l;
	t_list *expected;
	t_list *actual;

	l = ft_lstnew(strdup("1"));
	l->next = ft_lstnew(strdup("2"));
	l->next->next = ft_lstnew(strdup("3"));
	expected = l->next->next;
	actual = ft_lstlast(l);
	if (actual == expected)
		printf("succeed\n");
	printf("failes\n");
}
