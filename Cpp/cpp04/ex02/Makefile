SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp AWrongAnimal.cpp WrongCat.cpp Brain.cpp

NAME = Abstract

CC = c++

FLAGS = -Wall -Werror -Wextra -g -std=c++98

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