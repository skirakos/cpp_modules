NAME = animal

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Animal.cpp \
		main.cpp \
		Dog.cpp \
		Cat.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Makefile Animal.hpp Dog.hpp Cat.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
