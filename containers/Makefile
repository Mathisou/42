SRCS = main.cpp

SRCS_HPP = vector.hpp VectorIterator.hpp reverse_iterator.hpp

NAME = containers

CC = c++

FLAGS = -Wall -Werror -Wextra -g -std=c++98 -fsanitize=address -g3 -ferror-limit=40

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(SRCS_HPP)
	$(CC) $(FLAGS) -c $(SRCS) $(SRCS_HPP)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re:		fclean $(NAME)

.PHONY: all re clean fclean