# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Executable name
NAME = libft.a

# Source files
SRC = ft_strlen.c \
	ft_strncmp.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_isdigit.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isprint.c \
	ft_isascii.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_memset.c
#bzero
#memcpy
#memmove
#strlcpy
#memchr
#memcmp
#strnstr

#calloc


# Object files
OBJ = $(SRC:.c=.o)

# Main rule for compiling the project
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule for cleaning object files
clean:
	rm -f $(OBJ)

# Rule for fully cleaning the project (removing executable and object files)
fclean: clean
	rm -f $(NAME)

# Default rule
all: $(NAME)
	bash tests/run_tests.sh

re: fclean all

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re

