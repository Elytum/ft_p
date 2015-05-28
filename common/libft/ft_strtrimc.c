/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:23:33 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:23:39 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_strtrimc(char **s, char c)
{
	size_t		start;
	size_t		end;
	char		*tmp;

	start = 0;
	while ((*s)[start] && (*s)[start] == c)
		start++;
	end = ft_strlen(*s);
	if (start == end)
	{
		free(*s);
		*s = ft_strdup("");
	}
	else
	{
		end--;
		while (end && (*s)[end] == c)
			end--;
		end++;
		tmp = ft_strsub(*s, start, end - start);
		*s = tmp;
	}
}
