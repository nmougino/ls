/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:08:02 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 11:20:00 by nmougino         ###   ########.fr       */
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
}

void	long_display(t_ls_file *file)
{
	char		*tmp;
	const int	col[4] = {com_hl(file), com_owner(file),
		com_group(file), com_size(file)};

	ft_printf("total %d\n", disp_block(file));
	while (file)
	{
		disp_mode(file->filestat.st_mode);
		ft_printf("%*d %-*s  ", col[0], file->filestat.st_nlink,
			col[1], tmp = disp_owner(file->filestat.st_uid));
		free(tmp);
		ft_printf("%-*s  ", col[2], tmp = disp_group(file->filestat.st_gid));
		free(tmp);
		ft_printf("%*d %.7s%.5s ", col[3], file->filestat.st_size,
		ctime(&file->filestat.st_mtime) + 4,
			disp_time(file->filestat.st_mtime));
		ft_printf("%s", file->dp.d_name);
		if (S_ISLNK(file->filestat.st_mode))
			disp_link_target(file->path);
		write(1, "\n", 1);
		file = file->next;
	}
}
