# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 12:15:46 by tburakow          #+#    #+#              #
#    Updated: 2022/03/09 16:44:13 by tburakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c create_flags.c ft_raise_flags.c formats_one.c
SRC += formats_two.c check_for_char.c reset_flags.c print_out.c apply_flags.c \
octal_conversion.c hex_conversion.c to_ascii.c round.c
OBJ = $(SRC:.c=.o)
CFLAGS = -c -Wall -Werror -Wextra
NAME = libftprintf.a
LIBFTPATH = libft/
all: $(NAME)

$(NAME):
	@make -C $(LIBFTPATH)
	@cc $(CFLAGS) $(SRC) -I $(LIBFTPATH)
	@ar rc $(NAME) $(OBJ) $(LIBFTPATH)*.o
clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
re: fclean all
