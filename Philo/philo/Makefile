# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroly <maroly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 14:42:43 by maroly            #+#    #+#              #
#    Updated: 2022/02/12 02:54:18 by maroly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	philo.c			\
				utils.c			\
				utils2.c		\
				list_utils.c	\
				status.c		\

LIB			=	includes/philo.h

JSP			=	$(addprefix sources/, $(SRCS))

OBJS		=  	$(SRCS:.c=.o)

CC			= 	gcc

FLAGS		=   -Werror -Wextra -Wall -g3 -pthread

NAME		= 	philo

all			:	$(NAME)
		
$(OBJS)		:	$(LIB) $(JSP) $(LIB)
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) -c $(JSP)

$(LIBFT)	:	
				make -C sources/libft

$(NAME)		:	$(OBJS)
				@$(CC) $(FLAGS) -o $@ $(OBJS)
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

clean		:
				@rm -f $(OBJS)
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

re			:	fclean all

.PHONY		: 	all, clean, fclean, re
