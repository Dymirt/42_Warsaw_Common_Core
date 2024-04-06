# Compiler
CC = clang

# Compiler flags


# Executable name for the library
NAME = libftprintf.a

# Source files for ft_printf library
SRC = ft_printf.c ft_utoa.c ft_putnbr_base.c


# Rule for compiling libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft/

# Object files
OBJ = $(SRC:.c=.o)

# Main rule for compiling the project
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule for compiling individual source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./libft/

# Rule for compiling test file
test: all
	$(CC) $(CFLAGS) -o test_ft_printf .test_ft_printf.c -I$(LIBFT_DIR) -L. -lftprintf -L$(LIBFT_DIR) -lft

# Rule for cleaning object files and libraries
clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

# Rule for fully cleaning the project
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

# Default rule
re: fclean all

# Default rule
all:
	@make -C $(LIBFT_DIR)
	@make $(NAME)

# Phony targets to avoid conflicts with file names
.PHONY: all test clean fclean re
