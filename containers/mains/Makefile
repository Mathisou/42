SRCS_VECTOR = vector_main.cpp

SRCS_STACK = stack_main.cpp

SRCS_MAP = map_main.cpp

SRCS_DEQUE = deque_main.cpp

SRCS_LIST = list_main.cpp

NAME = containers

CC = c++

FLAGS = -Wall -Werror -Wextra -g -std=c++98 -fsanitize=address -g3

OBJS = $(SRCS_VECTOR:.cpp=.o)

OBJS_VECTOR = $(SRCS_VECTOR:.cpp=.o)

OBJS_STACK = $(SRCS_STACK:.cpp=.o)

OBJS_MAP = $(SRCS_MAP:.cpp=.o)

OBJS_DEQUE = $(SRCS_DEQUE:.cpp=.o)

OBJS_LIST = $(SRCS_LISt:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS_VECTOR)

vector: $(OBJS_VECTOR)
		$(CC) $(FLAGS) -c $(SRCS_VECTOR)
		@echo $(OBJS_VECTOR)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_VECTOR)

stack:	$(OBJS_STACK)
		$(CC) $(FLAGS) -c $(SRCS_STACK)
		@echo $(OBJS_STACK)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_STACK)

map:	$(OBJS_MAP)
		$(CC) $(FLAGS) -c $(SRCS_MAP)
		@echo $(OBJS_MAP)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_MAP)

deque:	$(OBJS_MAP)
		$(CC) $(FLAGS) -c $(SRCS_DEQUE)
		@echo $(OBJS_DEQUE)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_DEQUE)

list:	$(OBJS_MAP)
		$(CC) $(FLAGS) -c $(SRCS_LIST)
		@echo $(OBJS_LIST)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS_LIST)

clean:
		rm -rf outfiles/* $(OBJS) $(OBJS_MAP) $(OBJS_STACK) $(OBJS_DEQUE) $(OBJS_LIST)

fclean:		clean
		rm -rf $(NAME)

re:		fclean $(NAME)

.PHONY: all re clean fclean