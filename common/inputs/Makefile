#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glovichi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 21:34:10 by glovichi          #+#    #+#              #
#    Updated: 2015/04/22 09:00:48 by glovichi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = get_lines

SOURCES =	ft_arrows.c				\
			ft_arrows2.c			\
			ft_charmanage.c			\
			ft_clean.c				\
			ft_cursor.c				\
			ft_delete.c				\
			ft_env.c				\
			ft_inputs.c				\
			ft_lstrmanage.c			\
			ft_managechar.c			\
			ft_moves.c				\
			ft_put.c				\
			ft_special.c

SRC = $(addprefix srcs/, $(SOURCES))

OBJ = $(SRC:.c=.o)

LIBNAME = get_lines.a

FLAGS = -Wall -Werror -Wextra

HEAD = ./includes -I../libft

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) -I $(HEAD) $(FLAGS)
	@ar rc $(LIBNAME) $(OBJ)
	@ranlib $(LIBNAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIBNAME)

re: fclean all