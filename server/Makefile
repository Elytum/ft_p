# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 14:44:31 by dmansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -------------Compilateur------------------#
CC		=	gcc
#--------------Name-------------------------#
NAME	=	server
MYPATH	=	$(HOME)
#--------------Sources----------------------#
FILES_SERVER	=	server.c launcher_server.c

INC		=	-I./includes -I../common/includes -I../common/libft 
CCFLAGS	=	-Wall -Wextra -Werror -g
LIBS = ../common/common.a ../common/libft/libft.a

SRCS	=	$(addprefix srcs/, $(FILES_SERVER))
OBJS	=	$(SRCS:.c=.o)

#--------------Actions----------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(INC) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CCFLAGS) -c  $(INC) $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all

