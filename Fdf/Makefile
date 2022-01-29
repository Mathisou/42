# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maroly <maroly@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 14:42:43 by maroly            #+#    #+#              #
#    Updated: 2022/01/29 02:54:56 by maroly           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		=	fdf.c						\
				get_next_line.c 			\
				get_next_line_utils.c		\
				draw.c						\
				draw_utils.c				\
				utils.c						\
				utils2.c					\
				map.c						\
				controls.c					\
				controls_utils.c			\
				mouse.c						\
				rotation.c					\
				color.c						\
				

LIB			=	includes/fdf.h

JSP			=	$(addprefix sources/, $(SRCS))

OBJS		=  	$(SRCS:.c=.o)

CC			= 	gcc

MLX_INC		=	-I ./minilibx_macos

MLX_LNK		=	-L ./minilibx_macos -l mlx -framework OpenGL -framework Appkit -O3

FLAGS		=   -Werror -Wextra -Wall -g

NAME		= 	fdf

LIBFT		=	sources/libft/libft.a

all			:	$(NAME)
		
$(OBJS)		:	$(JSP) $(LIB) $(LIBFT)
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) $(MLX_INC) -c $(JSP)

$(LIBFT)	:	
				make -C sources/libft

$(NAME)		:	$(OBJS) $(LIBFT)
				@$(CC) $(FLAGS) $(MLX_LNK) -Lsources/libft -lft -o $@ $(OBJS)
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

clean		:
				@rm -rf $(OBJS)
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

re			:	fclean all

rebonus		:	fclean bonus

reboth		:	fclean all bonus

.PHONY		: 	all, clean, fclean, re