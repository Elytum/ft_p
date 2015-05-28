# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achazal <achazal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:54:29 by achazal           #+#    #+#              #
#    Updated: 2015/05/28 14:18:48 by folier           ###   ########.fr        #
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
PATH_LIBFT = libft
PATH_LIBFT_INC = $(PATH_LIBFT)/includes
INC		=	-I./includes -I./$(PATH_INC)/ -I./$(PATH_LIBFT)/ 
SRCS	=	test.c str_issort.c
OBJS	=	$(patsubst %.c, $(PATH_OBJS)/%.o, $(SRCS))
#--------------Actions----------------------#

all: $(NAME)

$(PATH_OBJS)/%.o: $(addprefix $(PATH_SRCS)/, %.c)
	@mkdir -p $(PATH_OBJS)
	$(CC) $(INC) -o $@ -c $< $(CCFLAGS)
	
$(NAME): $(PATH_LIBFT)/$(LIBFT) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib common.a
	@echo "Commonlib ok"

$(PATH_LIBFT)/$(LIBFT): $(PATH_LIBFT)/Makefile
	@cd $(PATH_LIBFT)/ && $(MAKE)

clean:
	@rm -rf $(PATH_OBJS)
	@rm -f $(OBJS)
	@cd $(PATH_LIBFT) && $(MAKE) $@
	
fclean:	clean
	rm -f $(NAME)
	rm -f $(PATH_LIBFT)/$(LIBFT)

re: fclean all

