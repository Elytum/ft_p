/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 05:49:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

typedef struct	s_message
{
	char		kind;
	size_t		len;
	char		error;
	char		*content;
}				t_message;

# define WELCOME_MESSAGE "ft_p\n"
# define WELCOME_MESSAGE_LEN sizeof(WELCOME_MESSAGE)
# define TRUE 1
# define FALSE 0
# define MAX_CLIENTS 30
# define BUFF_SIZE 1024
# define NAME_MAX 32
# define PATH_MAX 4096
# define LIFE_TIME 10
# define EXTRA_HEADER (sizeof(char) + sizeof(char))
# define HEADER_SIZE (sizeof(char) + sizeof(size_t))
# define S_IFTEXT 0b00000001

#endif