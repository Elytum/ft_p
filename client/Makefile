# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 15:34:11 by dmansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	client
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES_CLIENT	=	client.c

INC		=	-I./includes -I../common/includes -I../common/libft/
CCFLAGS	=	-Wall -Wextra -Werror -g
LIBS	=	../common/common.a ../common/libft/libft.a

SRCS	=	$(addprefix srcs/, $(FILES_CLIENT))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(LIBS) $(INC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all

