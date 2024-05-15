# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Executable name
NAME = push_swap

# Source files
SRC = main.c swap.c rotate.c 

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

# Rule for fully cleaning the project (removing executable and object files)
fclean: clean
	rm -f $(NAME)

# Default rule
all: $(NAME)

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean

