#include "libft.h"

t_list    *ft_lstnew(void *content)
{
    t_list    *result;

    result = (t_list *) malloc(sizeof(t_list));
    if (!result)
        return (NULL);
    result->content = content;
    //ft_lstnullterminate(result);
    return (result);
}
