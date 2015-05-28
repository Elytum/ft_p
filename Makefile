# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 15:12:30 by dmansour         ###   ########.fr        #
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
	make -C common
	make -C server
	make -C client

clean:
	make clean -C common
	make clean -C server
	make clean -C client
	
fclean:
	echo "PUTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIN"
	make fclean -C common
	make fclean -C server
	make fclean -C client

re: fclean all

