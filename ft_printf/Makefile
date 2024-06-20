# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 21:53:29 by dkolida           #+#    #+#              #
#    Updated: 2024/06/20 20:19:51 by dmytrokolid      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Executable name for the library
NAME = libftprintf.a

# Source files for ft_printf library
SRC =	ft_printf.c\
		ft_utoa.c\
		ft_memjoin.c\
		ft_ctoa.c\
		ft_utoa_base.c\
		ft_utob16.c\
		ft_utob16u.c\
		ft_swap_and_free.c\
		ft_printf_handle_s.c\
		ft_printf_handle_p.c\
		helpers.c\


# Rule for compiling libft
LIBFT_NAME = libft.a
LIBFT_DIR = ../libft/

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
