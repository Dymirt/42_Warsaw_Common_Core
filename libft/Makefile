# Compiler
CC = clang

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g -fdiagnostics-color=always

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
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_calloc.c	\
	ft_itoa.c \
	ft_striteri.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_sorted.c \
	ft_free_2d.c \
	is_arr_uniq.c \
	is_int_str.c \
	ft_arr_atoi.c \
	ft_compare.c\


# Object files
OBJDIR = obj/
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR),$(OBJ))

# Rule for compiling libft
FT_PRINTF_DIR = ft_printf/

# Main rule for compiling the project
$(NAME): $(OBJ)
	@make -C $(FT_PRINTF_DIR)
	ar rcs $(NAME) $(OBJ) $(FT_PRINTF_DIR)$(OBJDIR)*.o

# Rule for compiling individual source files
$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for cleaning object files
clean:
	rm -f $(OBJ)
	@make clean -C $(FT_PRINTF_DIR)
# Rule for fully cleaning the project (removing executable and object files)
fclean: clean
	rm -f $(NAME)
	-rm -r $(OBJDIR)
	@make fclean -C $(FT_PRINTF_DIR)

# Default rule
all: $(NAME)

re: fclean all

tests:	re
		bash .tests/run_tests.sh

# Phony targets to avoid conflicts with file names
.PHONY: all clean fclean re tests printf

