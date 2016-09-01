/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:25:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 19:13:42 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_meta(t_ls_meta *meta)
{
	if (meta->tarnb)
		while ((meta->tarnb)--)
			free(meta->target[meta->tarnb]);
	free(meta->target);
}

int			main(int ac, char **av)
{
	t_ls_meta	meta;

	if (!parser(ac, av, &meta))
		return (0);
	free_meta(&meta);
	return (0);
}
