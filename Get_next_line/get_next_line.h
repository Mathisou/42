/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <maroly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:59:48 by maroly            #+#    #+#             */
/*   Updated: 2021/12/07 17:34:12 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_strdup(char *str);
char	*split(char *str, char *new);
size_t	ft_strlen(const char *s);
char	*value_to_return(char *new_line, char *stock, char *buffer, int check);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
