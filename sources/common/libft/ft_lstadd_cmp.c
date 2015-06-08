/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:05:06 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:05:12 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_cmp(t_list **lst, t_list *new)
{
	t_list		*tmp1;
	t_list		*tmp2;
	size_t		min;

	tmp1 = *lst;
	min = ft_min(tmp1->content_size, new->content_size);
	if (ft_memcmp(new->content, tmp1->content, min) < 0)
	{
		ft_lstadd(lst, new);
		return ;
	}
	tmp2 = tmp1->next;
	while (tmp2 != NULL)
	{
		min = ft_min(tmp2->content_size, new->content_size);
		if (ft_memcmp(new->content, tmp2->content, min) < 0)
		{
			new->next = tmp2;
			tmp1->next = new;
			return ;
		}
		tmp1 = tmp2;
		tmp2 = tmp1->next;
	}
	tmp1->next = new;
}
