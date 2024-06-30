# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g -fdiagnostics-color=always

# Executable name
NAME = pipex

# Source files
SRC = main.c \
	validations.c \
	pipex_init.c \
	path.c \
	helpers.c \

# Rule for compiling libft
LIBFT_DIR = ../libft/

# Object files
OBJDIR = obj/
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR),$(OBJ))

# Main rule for compiling the project
$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

# Rule for compiling individual source files
$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
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

bonus : all

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re

