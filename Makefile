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
	make -C server
	make -C client
	
clean:
	make clean -C server
	make clean -C client
	make clean -C common
	
fclean:
	make fclean -C server
	make fclean -C client
	make fclean -C common

re: fclean all

