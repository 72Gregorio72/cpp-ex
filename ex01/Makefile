NAME = phoneBook
CC = c++ -Wall -Wextra -Werror -std=c++98
SRCS = Contact.cpp PhoneBook.cpp main.cpp
INCLUDES = .

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I$(INCLUDES)
all: $(NAME)
%.o : %.cpp
	$(CC) -c $< -o $@ -I$(INCLUDES)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
vale:
	@echo "Valgrind output:"
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)
re: fclean all
.PHONY: all clean fclean re