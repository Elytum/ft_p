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

#--------------Name-------------------------#
NAME	=	common.a
#--------------Sources----------------------#
INC		=	-I./includes
CCFLAGS	=	-Wall -Wextra -Werror -g
PATH_SRCS = srcs
PATH_OBJS = obj
PATH_INC = includes
SRCS	=	test.c
OBJS	=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))
#--------------Actions----------------------#

all: $(NAME)

$(PATH_OBJS)/%.o: $(addprefix $(PATH_SRCS)/, %.c)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(INC) -o $@ -c $< $(CCFLAGS)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib common.a
	@echo "Commonlib ok"
clean:
	@rm -rf $(PATH_OBJS)
	@rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all

