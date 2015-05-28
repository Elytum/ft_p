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

NAME = libft

SRC =	ft_atoi.c				\
		ft_bzero.c				\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_islower.c			\
		ft_isprint.c			\
		ft_isspace.c			\
		ft_isupper.c			\
		ft_itoa.c				\
		ft_memalloc.c			\
		ft_memccpy.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memdel.c				\
		ft_memmove.c			\
		ft_memset.c				\
		ft_putchar.c			\
		ft_putchar_fd.c			\
		ft_putendl.c			\
		ft_putendl_fd.c			\
		ft_putnbr.c				\
		ft_putnbr_fd.c			\
		ft_putstr.c				\
		ft_putstr_fd.c			\
		ft_putstrarray.c		\
		ft_strarraylen.c		\
		ft_strcat.c				\
		ft_strchr.c				\
		ft_strclr.c				\
		ft_strcmp.c				\
		ft_strcpy.c				\
		ft_strdel.c				\
		ft_strdup.c				\
		ft_strdup.c				\
		ft_strequ.c				\
		ft_strisin.c			\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strlen.c				\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strncat.c			\
		ft_strncmp.c			\
		ft_strncpy.c			\
		ft_strnequ.c			\
		ft_strnew.c				\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strrev.c				\
		ft_strstr.c				\
		ft_strsub.c				\
		ft_strtrim.c			\
		ft_swap.c				\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_putstrarray_fd.c		\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_strsplit.c			\
		ft_lstpush.c			\
		ft_putintarray.c		\
		ft_isodd.c				\
		ft_iseven.c				\
		ft_isodd_digit.c		\
		ft_iseven_digit.c		\
		ft_isword.c

OBJ = $(SRC:.c=.o)

LIBNAME = libft.a

FLAGS = -Wall -Werror -Wextra

HEAD = ./includes

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