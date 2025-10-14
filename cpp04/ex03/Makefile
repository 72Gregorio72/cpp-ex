NAME = interfaces
SRCS = main.cpp Character.cpp Ice.cpp Cure.cpp AMateria.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re