/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 04:33:17 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 04:35:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_lstatchg(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_ctime;
	tb = b->filestat.st_ctime;
	if (ta == tb)
	{
		ta = a->filestat.st_ctimespec.tv_nsec;
		tb = b->filestat.st_ctimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}
