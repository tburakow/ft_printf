# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 12:15:46 by tburakow          #+#    #+#              #
#    Updated: 2022/03/25 13:45:43 by tburakow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FUNCTIONS = ft_printf create_flags ft_raise_flags formats_one \
formats_two check_for_char reset_flags print_out apply_flags \
octal_conversion hex_conversion to_ascii round special_putchar \
apply_flags_two hex_cap_conversion ptr_conversion strjoin_with_free \
strsub_with_free char_mod float_mod

LIBFUNCS = libft/ft_atoi libft/ft_bzero libft/ft_free_array \
libft/ft_isalnum libft/ft_isalpha libft/ft_isascii libft/ft_isdigit \
libft/ft_isprint libft/ft_itoa libft/ft_lstadd libft/ft_lstdel \
libft/ft_lstdelone libft/ft_lstiter libft/ft_lstmap libft/ft_lstnew \
libft/ft_memalloc libft/ft_memccpy libft/ft_memchr libft/ft_memcmp \
libft/ft_memcpy libft/ft_memdel libft/ft_memmove libft/ft_memset \
libft/ft_putchar libft/ft_putchar_fd libft/ft_putendl \
libft/ft_putendl_fd libft/ft_putnbr libft/ft_putnbr_fd \
libft/ft_putstr libft/ft_putstr_fd libft/ft_strcat \
libft/ft_strchr libft/ft_strclr libft/ft_strcmp libft/ft_strcpy \
libft/ft_strdel libft/ft_strdup libft/ft_strequ libft/ft_striter \
libft/ft_striteri libft/ft_strjoin libft/ft_strlcat libft/ft_strlen \
libft/ft_strmap libft/ft_strmapi libft/ft_strncat libft/ft_strncmp \
libft/ft_strncpy libft/ft_strnequ libft/ft_strnew libft/ft_strnstr \
libft/ft_strrchr libft/ft_strsplit libft/ft_strstr libft/ft_strsub \
libft/ft_strtrim libft/ft_tolower libft/ft_toupper libft/ft_word_count

FILES = $(patsubst %, %.c, $(FUNCTIONS))
OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))
OBJS = $(LIBFUNCS:=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -c $(FILES)
	ar rcs $(NAME) $(OBJS) $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all

NAMETEST = a.out
FUNCTIONSTEST = ft_printf create_flags ft_raise_flags formats_one \
formats_two check_for_char reset_flags print_out apply_flags \
octal_conversion hex_conversion to_ascii round main special_putchar \
apply_flags_two hex_cap_conversion ptr_conversion strjoin_with_free \
strsub_with_free char_mod float_mod
FILESTEST = $(patsubst %, %.c, $(FUNCTIONSTEST))
OBJECTSTEST = $(patsubst %, %.o, $(FUNCTIONSTEST))

alltest: $(NAMETEST)

$(NAMETEST):
	make -C libft/
	gcc -Wall -Wextra -Werror -c -g $(FILESTEST)
	gcc -Wall -Werror -Wextra $(OBJECTSTEST) libft/libft.a -o $(NAMETEST)
	make fclean -C libft/

cleantest:
	rm -f $(OBJECTSTEST)

fcleantest: cleantest
	rm -rf $(NAMETEST)

retest: fcleantest alltest
