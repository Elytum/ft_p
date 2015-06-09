# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 09:54:01 by folier           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = common

SOURCES =	errors.c			\
			message_sending.c

SRC = $(addprefix srcs/, $(SOURCES))

OBJ = $(SRC:.c=.o)

LIBNAME = common.a

FLAGS = -Wall -Werror -Wextra

INC = -I./includes -I../libft -I./inputs/includes

all: $(NAME)

build:
	make -C inputs
	make -C libft

$(NAME): build $(OBJ)
	ar rc $(LIBNAME) $(OBJ)
	@ranlib $(LIBNAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(LIBNAME)

re: fclean all
