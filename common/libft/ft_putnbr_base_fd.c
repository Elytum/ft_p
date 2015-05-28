/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirigna <lsirigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:15:37 by lsirigna          #+#    #+#             */
/*   Updated: 2015/02/18 16:15:43 by lsirigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd2(unsigned int n, unsigned int base, int fd)
{
	char	val[16];

	val = "0123456789abcdef";
	if (base < 2 || base > 16)
		return ;
	if (n / base != 0)
	{
		ft_putnbr_base_fd2(n / base, base, fd);
		ft_putchar_fd(val[n % base], fd);
	}
	else
		ft_putchar_fd(val[n % base], fd);
}

void	ft_putnbr_base_fd(unsigned int n, unsigned int base, int fd)
{
	if (n < base)
		ft_putchar_fd('0', fd);
	ft_putnbr_base_fd2(n, base, fd);
}
