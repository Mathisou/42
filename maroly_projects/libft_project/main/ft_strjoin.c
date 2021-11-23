#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i])
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t i;
	size_t j;
	size_t size;
	char *new;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = NULL;
	new = (char *) malloc(sizeof(*new) * (size + 1));
	//printf("%d\n", size + 1);
	if (new == NULL)
		return (NULL);
	new = ft_strcat(new, (char *)s1);
	new = ft_strcat(new, (char *)s2);
	return (new);
}

int main(int ac, char **av)
{
        char *s1 = "where is my ";
        char *s2 = "malloc ???";
        char *s3 = "where is my malloc ???";

        char *res = ft_strjoin(s1, s2);
        if (!memcmp(res, s3, 24))
{
                printf("success\n");
return 0;
}
        printf("failed\n");
return 0;
	//printf("%d\n", ft_strjoin(NULL, NULL));
}
