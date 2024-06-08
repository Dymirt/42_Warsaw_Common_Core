# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Executable name
NAME = push_swap

# Source files
SRC = main.c swap.c rotate.c push.c valid_input.c reverse_rotate.c
# Rule for compiling libft
LIBFT_NAME = libft.a
LIBFT_DIR = libft/

# Object files
OBJ = $(SRC:.c=.o)

# Main rule for compiling the project
$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_DIR)*.o

# Rule for cleaning object files
clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)


# Rule for fully cleaning the project (removing executable and object files)
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

# Default rule
re: fclean all

# Default rule
all: $(NAME)

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re

