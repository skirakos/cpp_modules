NAME = convert

CPP = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		ScalarConverter.cpp \
		Serializer.cpp 
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp Makefile ScalarConverter.hpp Serializer.hpp Data.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
