/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:25:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 17:25:44 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_ls_meta	meta;
	int			i = 0;

	ft_printf("rendu parser: %d\n", parser(ac, av, &meta));
	ft_printf("parametres : %b\n", meta.param);
	while (i < meta.tarnb)
	{
		++i;
		ft_printf("filename %d : \"%s\"\n", i, meta.target[i - 1]);
	}
	return (0);
}
