/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:50:21 by maroly            #+#    #+#             */
/*   Updated: 2021/11/25 16:48:20 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <libgen.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*void	ft_putchar(int c);
void	ft_putnbr(int nb);
void	ft_swap(int *a, int *b);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_check_base(char *base);
void	ft_putnbr_base(int nbr, char *base);
int		ft_atoi_base(char *str, char *base);
int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_ultimate_strjoin(int size, char **strs, char *sep);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_stock_file(char *file_name);
void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *tab, int length, int (*f)(int));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));
void	ft_sort_string_tab(char **tab);
int		ft_count_strings(char **tab);
void	ft_sort_list(t_list *lst, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
int		ft_is_power_of_2(int nb);*/

#endif
