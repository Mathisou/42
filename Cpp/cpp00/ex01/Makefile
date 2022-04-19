SRCS = PhoneBook.cpp Contact.cpp main.cpp

INCS = 

NAME = PhoneBook

CC = g++

FLAGS = -Wall -Werror -Wextra -g -std=c++98 -fsanitize=address

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean $(NAME)

.PHONY: all re clean fclean