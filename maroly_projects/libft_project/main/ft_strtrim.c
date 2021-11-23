#include "libft.h"

int	check_string(char const c, char const *set)
{
    int i;

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
    size = ft_strlen(s1) - 1;
    new = NULL;
    while (check_string(s1[i], set) == 0)
        i++;
    while (check_string(s1[size], set) == 0)
        size--;
    while (i <= size)
    {
        i++;
        s++;
    }
    printf("%ld\n", s +1);
    new = (char *) malloc(sizeof(*new) * (s + 1));
    if (new == NULL)
        return (NULL);
    return (new);

}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t j;
    size_t size;
    char *new;

    i = 0;
    j = 0;
    size = ft_strlen(s1) - 1;
    new = count_size(s1, set);
    while (check_string(s1[i], set) == 0)
        i++;
    while (check_string(s1[size], set) == 0)
        size--;
    while (i <= size)
    {
        new[j] = (char)s1[i];
        j++;
        i++;
    }
    new[j] = '\0';
    return (new);
}

int main(int ac, char **av)
{
    char *s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
    char *s2 = "Hello \t  Please\n Trim me !";
    char *ret = ft_strtrim(s1, " \n\t");

    printf("%s\n", ret);
    if (!strcmp(ret, s2))
    {
        printf("Success\n");
        return 0;
    }
    printf("failed\n");
    //printf("%s\n", ft_strtrim(av[1], av[2]));
}
