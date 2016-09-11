/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:47:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 00:46:59 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_no(t_ls_file *a, t_ls_file *b)
{
	a = b;
	return (1);
}

int	sort_alpha(t_ls_file *a, t_ls_file *b)
{
	if (!a || !b)
		return (0);
	if (ft_strcmp(a->dp.d_name, b->dp.d_name) < 0)
		return (1);
	else
		return (0);
}

int	sort_time(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_mtime;
	tb = b->filestat.st_mtime;
	if (ta == tb)
	{
		ta = a->filestat.st_mtimespec.tv_nsec;
		tb = b->filestat.st_mtimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}

int	sort_last_access(t_ls_file *a, t_ls_file *b)
{
	long	ta;
	long	tb;

	ta = a->filestat.st_atime;
	tb = b->filestat.st_atime;
	if (ta == tb)
	{
		ta = a->filestat.st_atimespec.tv_nsec;
		tb = b->filestat.st_atimespec.tv_nsec;
		if (ta == tb)
			return (sort_alpha(a, b));
	}
	return ((ta - tb) > 0 ? 1 : 0);
}
