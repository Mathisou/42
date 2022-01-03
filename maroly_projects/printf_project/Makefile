# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroly <maroly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/28 17:44:54 by maroly            #+#    #+#              #
#    Updated: 2021/12/15 17:07:52 by maroly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c				\
				precision.c				\
				ft_printf_utils.c		\
				bonus.c					\
				ft_printf_utils2.c		\
				bonusminus.c 			\
				bonuswidths.c			\
				bonuswidthsminus.c 		\
				sixthfonction.c			\

SRCS_BONUS	=	ft_printf.c				\
				precision.c				\
				ft_printf_utils.c		\
				bonus.c					\
				ft_printf_utils2.c		\
				bonusminus.c 			\
				bonuswidths.c			\
				bonuswidthsminus.c 		\
				sixthfonction.c			\

OBJS		=  	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

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

clean		:
				@rm -rf *.o
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

bonus		:	$(OBJS_BONUS)
				@ar rc $(NAME) $(OBJS_BONUS)
				@ranlib $(NAME)


re			:	fclean all

.PHONY		: 	all, clean, fclean, re
