/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 08:27:30 by achazal           #+#    #+#             */
/*   Updated: 2015/01/22 08:27:30 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inputs.h>

// static void		ft_update_shlvl(t_env *e)
// {
// 	char		**shlvl;
// 	char		*v;

// 	if ((shlvl = ft_get_env_addr(e, "SHLVL")))
// 	{
// 		v = ft_itoa(ft_atoi(*shlvl + 6) + 1);
// 		ft_set_env_value(e, "SHLVL", v);
// 		free(v);
// 	}
// 	else
// 		ft_set_env_value(e, "SHLVL", "1");
// }

// static void		ft_linkpathfree(char **str, char *new, char c)
// {
// 	char		*tmp;

// 	tmp = ft_linkpath(*str, new, c);
// 	free(*str);
// 	*str = tmp;
// }

t_env			*ft_get_env(char **envp)
{
	t_env		*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(0);
	e->name = ft_strdup("Shell > ");
	// if (!(e->p = ft_get_params()))
	// 	exit(0);
	if (!(e->str = ft_strdup("")))
		exit(0);
	e->max = 0;
	e->index = 0;
	if (!(e->histo = (t_str *)ft_memalloc(sizeof(t_str))))
		exit(0);
	// e->env = ft_dup_environ(envp);
	// e->pwd = ft_get_env_value(e, "PWD");
	// e->home = ft_get_env_value(e, "HOME");
	// e->oldpwd = ft_get_env_value(e, "OLDPWD");
	// ft_ironshell(e);
	// ft_update_shlvl(e);
	e->binpath = NULL;
	return (e);
	(void)envp;
}
