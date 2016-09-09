/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:08:02 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 13:28:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		disp_block(t_ls_file *file)
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

void	disp_mode(mode_t mode)
{
	disp_mode_type(mode);
	disp_mode_owner(mode);
	disp_mode_group(mode);
	disp_mode_other(mode);
	write(1, " ", 1);
}

void	disp_size_mm(t_ls_file *file, int *col)
{
	int			major;
	int			minor;

	if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
	{
		major = file->filestat.st_rdev;
		minor = file->filestat.st_rdev;
		while ((major / 256) > 0)
			major /= 256;
		minor = minor % 256;
		ft_printf("%*d, %*d ", col[3], major, col[4], minor);
	}
	else
		ft_printf("%*d ", col[5], file->filestat.st_size);
}

void	long_display(t_ls_file *file)
{
	char		*tmp;
	const int	col[6] = {com_hl(file), com_owner(file), com_group(file),
		com_major(file), com_minor(file),
		ft_max(com_size(file), col[3] + col[4] + 2)};

	ft_printf("total %d\n", disp_block(file));
	while (file)
	{
		disp_mode(file->filestat.st_mode);
		ft_printf("%*d %-*s  ", col[0], file->filestat.st_nlink,
			col[1], tmp = disp_owner(file->filestat.st_uid));
		free(tmp);
		ft_printf("%-*s  ", col[2], tmp = disp_group(file->filestat.st_gid));
		free(tmp);
		disp_size_mm(file, (int *)col);
		ft_printf("%.7s%.5s ", ctime(&file->filestat.st_mtime) + 4,
			disp_time(file->filestat.st_mtime));
		ft_printf("%s", file->dp.d_name);
		if (S_ISLNK(file->filestat.st_mode))
			disp_link_target(file->path);
		write(1, "\n", 1);
		file = file->next;
	}
}
