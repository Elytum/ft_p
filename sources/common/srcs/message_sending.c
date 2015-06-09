/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 05:49:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <common.h>
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void			value_mcopy(char **ptr, size_t value, size_t n)
{
	size_t			i;
	union s_value	v;

	if (n > sizeof(size_t))
		put_exit(2, "Value_mcopy error : N too big", -1);
	v.value = value;
	i = 0;
	while (i < n)
	{
		**ptr = v.compo[n - i - 1];
		(*ptr)++;
		i++;
	}
}

static size_t		value_mextract(char **ptr, size_t n)
{
	size_t			i;
	union s_value	v;

	if (n > sizeof(size_t))
		put_exit(2, "Value_mextract error : N too big", -1);
	n = sizeof(size_t) - n;
	i = 0;
	while (i < n)
		v.compo[sizeof(size_t) - i++ - 1] = 0;
	while (i < sizeof(size_t))
	{
		v.compo[sizeof(size_t) - i++ - 1] = **ptr;
		(*ptr)++;
	}
	return (v.value);
}

static char			ft_decode_errors(size_t len, size_t header_len)
{
	if (len != header_len)
		return (1);
	else
		return (0);
}

t_message			*ft_decode_message(const char *message)
{
	t_message		*decoded;
	// char			*ptr;

	(void)message;
	// if (!(decoded = (t_message *)malloc(sizeof(t_message))))
	if (!(decoded = (t_message *)malloc(1)))
		put_exit(2, "Malloc error", -1);
	// free(decoded);
	// free(decoded);
	// decoded->content = "Ceci est un test";
	// decoded->len = 16;
	// ptr = (char *)message;
	// decoded->kind = value_mextract(&ptr, sizeof(decoded->kind));
	// decoded->len = value_mextract(&ptr, sizeof(decoded->len));
	// decoded->content = strndup(ptr, decoded->len);
	// decoded->error = ft_decode_errors(strlen(decoded->content), decoded->len);
	return (NULL);
}

void				ft_code_message(char kind, char *content, char **arg)
{
	char			*coded;
	char			*ptr;
	size_t			len;

	len = strlen(content);
	if (!((*arg) = (char *)malloc(sizeof(char) * HEADER_SIZE + len + 1)))
		return ;
	ptr = (*arg);
	value_mcopy(&ptr, kind, sizeof(kind));
	value_mcopy(&ptr, len, sizeof(len));
	strcpy(ptr, content);
	ptr[len] = '\0';
}
