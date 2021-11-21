#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new_elem;

	new_elem = NULL;
	new_elem = malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	new_elem->content = content;
	return (new_elem);
}

int main(int ac, char **av)
{
	char *a = "Hello";
	char *c = "Everyone";
	t_list *b;

	b = malloc(sizeof(t_list));
	b->content = c;
	printf("before = %s\n", b->content);
	b = ft_lstnew(a);
	printf("after = %s\n", b->content);
}
