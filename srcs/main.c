/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:25:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 11:04:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_ls_meta		meta;
	register int	i;

	i = 0;
	parser(ac, av, &meta);
	while (i < meta.tarnb)
	{
		if (meta.param & (1 << 4))
			ls_rec(&meta, meta.target[i]);
		else
			ls_std(&meta, meta.target[i]);
		++i;
	}
	free_meta(&meta);
	return (0);
}
