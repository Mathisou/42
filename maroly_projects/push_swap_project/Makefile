SRCS		=	push_swap.c				\
				moves.c					\
				check.c					\
				utils.c					\
				manipulating_lists.c	\
				end_algo.c				\
				call_moves.c			\
				find_best_movement.c	\
				manipulating_lists2.c	\
				find_median.c			\
				first_algo.c			\

SRCS_BONUS	=	checker.c				\
				checker_utils.c			\
				manipulating_lists2.c	\
				moves.c					\
				check.c					\
				utils.c					\
				call_moves.c			\
				manipulating_lists.c	\

OBJS		=  	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			= 	gcc

FLAGS		=   -Wall -Wextra -Werror -fsanitize=address

NAME		= 	push_swap

NAME_BONUS	=	checker

LIBFT		=	libft/libft.a

all			:	$(NAME)

.c.o		:	push_swap.h
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) -c $<

$(LIBFT)	:	
				make -C libft

$(NAME)		:	$(OBJS) $(LIBFT) 
				@$(CC) $(FLAGS) -o $@ $^ -Llibft/ -lft
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

bonus		:	$(OBJS_BONUS) $(LIBFT)
				@$(CC) $(FLAGS) -o $(NAME_BONUS) $^ -Llibft/ -lft
				@echo "\t\t\t\t \033[33;32mDONE.\033[33;32m"

clean		:
				@rm -rf *.o libft/*.o
				@echo "\t\t      \x1b[31mfiles .o deleted successfully.\x1b[31m"

fclean		:	clean
				@rm -f $(NAME) $(NAME_BONUS) $(LIBFT)
				@echo "\t\t       \x1b[31m$(NAME) deleted sucessfully.\x1b[31m"

re			:	fclean all

rebonus		:	fclean bonus

reboth		:	fclean all bonus

.PHONY		: 	all, clean, fclean, re
