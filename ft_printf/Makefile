# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Executable name for the library
NAME = libftprintf.a

# Source files for ft_printf library
SRC = ft_printf.c ft_utoa.c

# Rule for compiling libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft/

# Object files
OBJ = $(SRC:.c=.o)

# Main rule for compiling the project
$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)*.o

# Rule for compiling individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for compiling test file
test: re
	$(CC) $(CFLAGS) -o .test_ft_printf .test_ft_printf.c -I. -L. -lftprintf

# Rule for cleaning object files and libraries
clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

# Rule for fully cleaning the project
fclean:
	rm -f $(NAME)
	rm -f $(OBJ)
	@make fclean -C $(LIBFT_DIR)

# Default rule
re: fclean all

# Default rule
all: $(NAME)

# Phony targets to avoid conflicts with file names
.PHONY: all test clean fclean re
