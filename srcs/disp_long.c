/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:08:02 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/18 23:49:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			disp_block(t_ls_file *file)
{
	int	ans;

	ans = 0;
	while (file)
	{
		ans += file->filestat.st_blocks;
		file = file->next;
	}
	return (ans);
}

void		disp_mode(mode_t mode)
{
	disp_mode_type(mode);
	disp_mode_owner(mode);
	disp_mode_group(mode);
	disp_mode_other(mode);
}

void		disp_size_mm(t_ls_file *file, int *col)
{
	int	tmp;

	if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
	{
		tmp = file->filestat.st_rdev;
		ft_printf("%*d, %*d ", col[3], (tmp >> 24) & 0xFF, col[4], tmp & 0xFF);
	}
	else
		ft_printf("%*ld ", col[5], file->filestat.st_size);
}

static void	disp_loop(t_ls_file *file, int param, int *col)
{
	char		*tmp;

	disp_mode(file->filestat.st_mode);
	disp_acl(file->path);
	ft_printf("%*d %-*s  ", col[0], file->filestat.st_nlink,
		col[1], tmp = disp_owner(file->filestat.st_uid, param));
	free(tmp);
	ft_printf("%-*s  ", col[2], tmp = disp_group(file->filestat.st_gid,
		param));
	free(tmp);
	disp_size_mm(file, (int *)col);
	ft_printf("%.7s%.5s %s", ctime(&file->filestat.st_mtime) + 4,
		disp_time(file->filestat.st_mtime), file->dp.d_name);
	(param & (1 << 6)) ? disp_mf(file->filestat.st_mode) : 0;
	(param & (1 << 10)) ? disp_p(file->filestat.st_mode, param) : 0;
	(S_ISLNK(file->filestat.st_mode)) ? disp_link_target(file->path) : 0;
	write(1, "\n", 1);
}

void		long_display(t_ls_file **ptr, int param)
{
	t_ls_file	*file;
	const int	col[6] = {com_hl(*ptr), com_owner(*ptr, param),
		com_group(*ptr, param), com_major(*ptr), com_minor(*ptr),
		ft_max(com_size(*ptr), col[3] + col[4] + 2)};

	check_perm(ptr);
	file = *ptr;
	if (file && file->dp.d_namlen)
		ft_printf("total %d\n", disp_block(file));
	while (file)
	{
		disp_loop(file, param, (int *)col);
		file = file->next;
	}
}
