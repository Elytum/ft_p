# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 15:27:06 by dmansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------Name-------------------------#
NAME	=	common.a
#--------------Sources----------------------#
LIBFT   = libft.a
CCFLAGS	=	-Wall -Wextra -Werror -g
PATH_SRCS = srcs
PATH_OBJS = obj
PATH_INC = includes
INC		=	-I./includes -I./$(PATH_INC)/ -I./libft 
SRCS	=	test.c str_issort.c
OBJS	=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))
COMPLIB	=	libft
#--------------Actions----------------------#

all: $(NAME)

$(PATH_OBJS)/%.o: $(addprefix $(PATH_SRCS)/, %.c)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(INC) -o $@ -c $< $(CCFLAGS)
	
$(NAME): $(LIBFT) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib common.a
	@echo "Commonlib ok"

$(LIBFT):
	make -C libft


clean:
	@rm -rf $(PATH_OBJS)
	@rm -f $(OBJS)
	make clean -C libft
	
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

