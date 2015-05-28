/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:04:38 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:04:44 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = NULL;
	while ((*lst)->next != NULL)
	{
		tmp2 = (*lst)->next;
		(*lst)->next = tmp1;
		tmp1 = *lst;
		*lst = tmp2;
	}
	(*lst)->next = tmp1;
}
