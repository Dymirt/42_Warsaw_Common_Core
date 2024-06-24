# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmytrokolida <dmytrokolida@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 21:53:29 by dkolida           #+#    #+#              #
#    Updated: 2024/06/24 02:52:10 by dmytrokolid      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = clang

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

OBJDIR = obj/

# Rule for compiling libft
LIBFT_DIR = ../

# Object files
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJDIR),$(OBJ))


## Main rule for compiling the project
$(NAME): $(OBJ)
#	@make printf -C $(LIBFT_DIR)
	ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)$(OBJDIR)*.o

# Rule for compiling individual source files
$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for cleaning object files and libraries
clean:
	rm -f $(OBJ)
#	@make clean -C $(LIBFT_DIR)

# Rule for fully cleaning the project
fclean: clean
	-rm -r $(OBJDIR)
#	@make fclean -C $(LIBFT_DIR)

# Default rule
re: fclean all

# Default rule
all: $(NAME)

# Phony targets to avoid conflicts with file names
.PHONY: all test clean fclean re
