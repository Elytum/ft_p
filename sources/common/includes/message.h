/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 05:49:07 by achazal           #+#    #+#             */
/*   Updated: 2015/06/08 05:49:10 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H
# include <config.h>

t_message	*ft_decode_message(const char *message, const size_t valread);
void		ft_code_message(char kind, char *content, size_t len, char **arg);

#endif