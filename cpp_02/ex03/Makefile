NAME = fixed

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Fixed.cpp \
		main.cpp \
		Point.cpp \
		bsp.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Makefile Fixed.hpp Point.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
