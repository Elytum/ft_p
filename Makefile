# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2014/12/13 12:55:35 by achazal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	ft_p
MYPATH	=	$(HOME)
#--------------Actions----------------------#

all: $(NAME)

$(NAME):
	make -C sources/server
	make -C sources/client
	cp sources/client/client ./
	cp sources/server/server ./
	
clean:
	make clean -C sources/server
	make clean -C sources/client
	make clean -C sources/common
	
fclean:
	make fclean -C sources/server
	make fclean -C sources/client
	make fclean -C sources/common

re: fclean all

