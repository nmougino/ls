/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:27:59 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 17:25:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	parser_init_empty(t_ls_meta *meta)
{
	meta->tarnb = 1;
	meta->target = (char **)malloc(sizeof(char *));
	*(meta->target) = ".";
}

static int	parser_add_param(t_ls_meta *meta, char *arg)
{
	register int	i;

	i = 0;
	if (!arg[1])
		return (0);
	while (arg[++i])
	{
		if (ft_strnloc(arg[i], "trlaR", 5) < 0)
			return (error_w_param(arg[i]));
		meta->param |= 1 << ft_strnloc(arg[i], "trlaR", 5);
	}
	return (1);
}

static void	parser_init_target(t_ls_meta *meta, char **av, int i, int ac)
{
	register int	c;

	c = 0;
	meta->tarnb = ac - i;
	meta->target = (char **)malloc(sizeof(char *) * ac - i);
	while (i < ac)
	{
		meta->target[c] = ft_strdup(av[i]);
		++c;
		++i;
	}
}

int		parser(int ac, char **av, t_ls_meta *meta)
{
	register int	i;

	i = 0;
	if (ac == 1)
	{
		meta->param = 0;
		parser_init_empty(meta);
	}
	else
	{
		meta->param = 0;
		while (++i < ac && av[i][0] == '-')
		{
			if (parser_add_param(meta, av[i]) < 0)
				return (-1);
		}
		if (i >= ac)
			parser_init_empty(meta);
		else
			parser_init_target(meta, av, i, ac);
	}
	return (1);
}
