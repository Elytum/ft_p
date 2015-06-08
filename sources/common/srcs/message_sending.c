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

static char			ft_decode_errors(size_t len,
	size_t header_len, size_t coded_len)
{
	if (len != header_len)
		return (1);
	else if (len != coded_len - HEADER_SIZE)
		return (2);
	else
		return (0);
}

t_message			*ft_decode_message(const char *message,
						const size_t coded_len)
{
	t_message		*decoded;
	char			*ptr;

	if (!(decoded = (t_message *)malloc(sizeof(t_message))))
		put_exit(2, "Malloc error", -1);
	decoded->content = NULL;
	if (coded_len < HEADER_SIZE)
	{
		decoded->error = 1;
		return (decoded);
	}
	ptr = (char *)message;
	decoded->kind = value_mextract(&ptr, sizeof(decoded->kind));
	decoded->len = value_mextract(&ptr, sizeof(decoded->len));
	if (decoded->len != coded_len - HEADER_SIZE)
	{
		decoded->error = 3;
		return (decoded);
	}
	decoded->content = strndup(ptr, coded_len - HEADER_SIZE);
	decoded->error = ft_decode_errors(strlen(decoded->content),
							decoded->len, coded_len);
	return (decoded);
}

void				ft_code_message(char kind, char *content,
						char **arg, size_t *arg_len)
{
	char			*coded;
	char			*ptr;
	size_t			len;

	len = strlen(content);
	*(arg_len) = sizeof(char) * HEADER_SIZE + len;
	if (!((*arg) = (char *)malloc(*(arg_len) + 1)))
		return ;
	ptr = (*arg);
	value_mcopy(&ptr, kind, sizeof(kind));
	value_mcopy(&ptr, len, sizeof(len));
	strcpy(ptr, content);
	ptr[len] = '\0';
}
