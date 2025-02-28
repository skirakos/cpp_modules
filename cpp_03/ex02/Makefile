NAME = fragtrap

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp \
		main.cpp \
		ScavTrap.cpp \
		FragTrap.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Makefile ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
