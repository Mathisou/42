#include "libft.h"

int	create_tab(char const *s, char c)
{
    int	i;
    int	size;

    i = 0;
    size = 0;
    while (s[i])
    {
        if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
            size++;
        i++;
    }
    return (size);
}

char *put_str_in_tab(const char *s, char c)
{
    size_t i;
    char *str;

    str = NULL;
    i = 0;
    while (s[i] != c && s[i])
        i++;
    str = (char *) malloc(sizeof(*str) * (i + 1));
    i = 0;
    while (s[i] && s[i] != c)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **ft_split(char const *s, char c)
{
    size_t i;
    size_t string;
    char **tab;

    i = 0;
    string = 0;
    tab = NULL;
    tab = (char **) malloc(sizeof(*tab) * (create_tab(s, c) + 1));
    if (tab == NULL)
        return (NULL);
    while (s[i])
    {
        while (s[i] == c && s[i])
            i++;
        if (((s[i - 1] == c || i == 0) && s[i] != c) && s[i])
        {
            tab[string] = put_str_in_tab(&s[i], c);
            string++;
        }
        if (s[i])
            i++;
    }
    tab[string] = NULL;
    return (tab);
}

int main()
{
    char **tab;
      int i;
    char *s = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.";

char c = 'z';
      i = 0;
      tab = malloc(sizeof(*tab) * create_tab(s, c + 1));
      tab = ft_split(s, c);
      while (i < create_tab(s, c))
      {
      printf("%s\n", tab[i]);
      i++;
      }
    /*char *s = "split  ||this|for|me|||||!|";
    int i = 0;
    char **result = ft_split(s, '|');
    char **expected;

    expected[0] = "split  ";
    expected[1] = "this";
    expected[2] = "for";
    expected[3] = "me";
    expected[4] = "!";
    while (result[i])
    {
        if (strcmp(result[i], expected[i]))
        {
            printf("failed\n");
            return 0;
        }
        free(result[i]);
        i++;
    }
    free(result);
    printf("Success\n");*/
}
