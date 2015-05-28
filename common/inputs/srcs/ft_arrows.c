/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 21:38:02 by achazal           #+#    #+#             */
/*   Updated: 2015/03/04 21:38:02 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inputs.h>

static void	ft_shellup(t_env *e)
{
	if (e->phisto->next)
	{
		// dprintf(1, "UP KEY\n");
		ft_clear_input(e);
		// dprintf(1, "UP KEY 1\n");
		free(e->phisto->tmp);
		// dprintf(1, "UP KEY 2\n");
		e->phisto->tmp = ft_strdup(e->str);
		// dprintf(1, "UP KEY 3\n");
		e->phisto = e->phisto->next;
		// dprintf(1, "UP KEY 4\n");
		if (!e->phisto->tmp)
			e->phisto->tmp = ft_strdup(e->phisto->str);
		// dprintf(1, "UP KEY 5\n");
		free(e->str);
		// dprintf(1, "UP KEY 6\n");
		e->str = ft_strdup(e->phisto->tmp);
		// dprintf(1, "UP KEY 7\n");
		e->max = ft_strlen(e->str);
		// dprintf(1, "UP KEY 8\n");
		e->index = e->max;
		// dprintf(1, "UP KEY 9\n");
		tputs(e->str, 1, ft_putc);
		// dprintf(1, "UP KEY 10\n");
	}
}

static void	ft_shelldown(t_env *e)
{
	if (e->phisto != e->histo)
	{
		ft_clear_input(e);
		free(e->phisto->tmp);
		e->phisto->tmp = ft_strdup(e->str);
		e->phisto = e->phisto->past;
		if (!e->phisto->tmp)
			e->phisto->tmp = ft_strdup(e->phisto->str);
		free(e->str);
		e->str = ft_strdup(e->phisto->tmp);
		e->max = ft_strlen(e->str);
		e->index = e->max;
		tputs(e->str, 1, ft_putc);
	}
}

static void	ft_leftright(t_env *e, char *inputs)
{
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 68)
	{
		// dprintf(1, "LEFT KEY\n");
		if (e->index > 0)
			ft_goleft(e);
		else
			tputs(tgetstr("bl", (char **)&(e->buf)), 1, ft_putc);
	}
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 67)
	{
		// dprintf(1, "RIGHT KEY\n");
		if (e->max > e->index)
			ft_goright(e);
		else
			tputs(tgetstr("bl", (char **)&(e->buf)), 1, ft_putc);
	}
}

int			ft_arrows(t_env *e, char *inputs)
{
	ft_leftright(e, inputs);
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 66)
		ft_shelldown(e);
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 65)
		ft_shellup(e);
	if ((inputs[0] == 27 && inputs[1] == 91) && (inputs[2] == 65 ||
		inputs[2] == 66 || inputs[2] == 67 || inputs[2] == 68))
		return (1);
	if ((inputs[0] == 27 && inputs[1] == 91 && inputs[2] == 49 &&
		inputs[3] == 59 && inputs[4] == 50) && (inputs[5] == 65 ||
		inputs[5] == 66 || inputs[5] == 67 || inputs[5] == 68))
	{
		ft_arrows2(e, inputs[5]);
		return (1);
	}
	if (inputs[0] == 27 && inputs[1] == 91 && inputs[3] == 0 &&
		inputs[4] == 0 && inputs[5] == 0 && inputs[6] == 0 &&
		((inputs[2] == 70) || inputs[2] == 72))
	{
		ft_special(e, inputs[2]);
		return (1);
	}
	return (0);
}
