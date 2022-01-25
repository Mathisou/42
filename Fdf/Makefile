# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroly <maroly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 14:42:43 by maroly            #+#    #+#              #
#    Updated: 2022/01/25 20:27:55 by maroly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	fdf.c						\
				get_next_line.c 			\
				get_next_line_utils.c		\
				ft_atoi_base.c				\
				draw.c						\
				utils.c						\
				map.c						\
				controls_utils.c			\
				mouse.c						\
				

LIB			=	fdf.h

OBJS		=  	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			= 	gcc

MLX_INC		=	-I ./minilibx_macos

MLX_LNK		=	-L ./minilibx_macos -l mlx -framework OpenGL -framework Appkit

FLAGS		=   -Werror -Wextra -Wall -g

NAME		= 	fdf

LIBFT		=	libft/libft.a

all			:	$(NAME)
		
.c.o		:	$(SRCS) $(LIB) $(LIBFT)
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) $(MLX_INC) -c $<

$(LIBFT)	:	
				make -C libft

$(NAME)		:	$(OBJS) $(LIBFT)
				@$(CC) $(FLAGS) $(MLX_LNK) -o $@ $^
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

bonus		:	$(OBJS_BONUS)
				@$(CC) $(FLAGS) -o $(NAME) $^
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

clean		:
				@rm -rf *.o
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

re			:	fclean all

rebonus		:	fclean bonus

reboth		:	fclean all bonus

.PHONY		: 	all, clean, fclean, re