SRCS		=	pipex.c					\
				pipex_utils.c			\
				pipex_utils2.c 			\
				here_doc.c				\
				ft_split.c				\

SRCS_BONUS	=	pipex_bonus.c			\
				pipex_utils_bonus.c		\
				pipex_utils2_bonus.c	\
				here_doc_bonus.c		\
				ft_split_bonus.c		\

OBJS		=  	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			= 	gcc

FLAGS		=   -Wall -Wextra -Werror

NAME		= 	pipex

all			:	$(NAME)
		
.c.o		:	 	
				@echo "\t\t    \033[33;32mCreation of $(NAME) in progress...\033[33;32m"
				@$(CC) $(FLAGS) -c $<

$(NAME)		:	$(OBJS)
				@$(CC) $(FLAGS) -o $@ $^
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
