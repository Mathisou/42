/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:12 by maroly            #+#    #+#             */
/*   Updated: 2021/11/23 14:57:17 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncats(char *dest, const char *src, size_t n)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i] && i < n)
	{
		dest[size + i] = (char)src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = NULL;
	while (s[i] && i != start)
		i++;
	while (s[i + j] && j < len)
		j++;
	new = (char *) malloc(sizeof(*new) * (j + 1));
	if (new == NULL)
		return (NULL);
	return (ft_strncats(new, &s[i], len));
}

int main()
{
	char str[] = "i just want this part #############";
        size_t size = 20;

        char *ret = ft_substr(str, 5, size);
        str[size + 5] = 0;
        if (!memcmp(ret, str + 5, size + 1))
        {
                free(ret);
                printf("success\n");
		return 0;
        }
        free(ret);
        printf("failed\n");

}
