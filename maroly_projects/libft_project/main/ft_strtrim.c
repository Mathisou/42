#include "libft.h"

int	check_string(char const c, char const *set)
{
    size_t i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
            return (0);
        i++;
    }
    return (1);
}

char	*count_size(char const *s1, char const *set)
{
    size_t i;
    size_t size;
    size_t s;
    char *new;

    i = 0;
    s = 0;
    size = ft_strlen(s1) - 1;
    new = NULL;
    while (check_string(s1[i], set) == 0)
        i++;
    while (check_string(s1[size], set) == 0)
        size--;
    while (i++ <= size)
        s++;
    new = (char *) malloc(sizeof(*new) * (s + 1));
    if (new == NULL)
        return (NULL);
    return (new);

}

char *create_str(char const *s1, char const *set)
{
    size_t i;
    size_t size;
    size_t j;
    char *new;

    i = 0;
    j = 0;
    new = NULL;
    size = ft_strlen(s1) - 1;
    while (check_string(s1[i], set) == 0)
    {
        i++;
        if (s1[i] == '\0')
            return ("\0");
    }
    while (check_string(s1[size], set) == 0)
        size--;
    if (count_size(s1,set) == NULL)
        return (NULL);
    else
        new = count_size(s1, set);
    while (i <= size)
        new[j++] = (char)s1[i++];
    new[j] = '\0';
    return (new);
}

char *ft_strtrim(char const *s1, char const *set)
{
    int size;
    char *new;

    size = ft_strlen(s1);
    new = NULL;
    if (size > 0)
    {
        if (create_str(s1, set) == NULL)
            return (NULL);
        else
            new = create_str(s1, set);
    }
    else
    {
        new = malloc(sizeof(*new) * 1);
        if (new == NULL)
            return (NULL);
        new[0] = '\0';
    }
    return (new);
}

int main()
{
   /* char *s1 = "";
    char *s2 = "";
    char *ret = ft_strtrim(s1, " s");

    printf("%s\n", ret);
    if (!strcmp(ret, s2))
    {
        printf("Success\n");
        return 0;
    }
    printf("failed\n");*/
    //printf("%s\n", ft_strtrim(av[1], av[2]));       
	char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";

	char *ret = ft_strtrim(s1, " \n\t");
	if (ret == ((void *)0))
		printf("success\n");
	printf("failed\n");
}
