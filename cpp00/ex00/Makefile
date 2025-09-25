NAME = megaphone
CC = c++ -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)
all: $(NAME)
%.o : %.cpp
	$(CC) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re