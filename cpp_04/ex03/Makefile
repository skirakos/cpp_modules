NAME = animal

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS = AMateria.cpp \
		main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Makefile AMateria.hpp Ice.hpp ICharacter.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
