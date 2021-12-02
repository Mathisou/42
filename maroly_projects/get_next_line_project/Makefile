# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroly <maroly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 19:00:13 by maroly            #+#    #+#              #
#    Updated: 2021/12/02 19:00:51 by maroly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	get_next_line.c				\
				get_next_line_utils.c		\

OBJS		=  	$(SRCS:.c=.o)

CC			= 	gcc

FLAGS		= 	-Wall -Wextra -Werror

NAME		= 	libftprintf.a

all			:	$(NAME)

.c.o		:
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) -c $<

$(NAME)		:	$(OBJS)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

bonus		:	$(OBJS_BONUS)
				@ar rc $(NAME) $(OBJS_BONUS)
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

clean		:
				@rm -rf *.o
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

re			:	fclean all

.PHONY		: 	all, clean, fclean, re
