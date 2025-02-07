# Name of the executable
NAME = phonebook

# Compiler
CPP = c++

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c++98

# Source files
SRCS = PhoneBook.cpp \
		Contact.cpp \
		main.cpp
		
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the target
all: $(NAME)

# Rule to link the executable
$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp Makefile Contact.hpp PhoneBook.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS)

# Full clean: remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Clean up and rebuild
re: fclean all

# Phony targets
.PHONY: all clean fclean re
