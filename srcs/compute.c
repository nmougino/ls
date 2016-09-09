/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 06:43:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 13:06:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	com_name(t_ls_file *file)
{
	int	ans;
	int	tmp;

	ans = 0;
	while (file)
	{
		tmp = ft_strlen(file->dp.d_name);
		if (ans < tmp)
			ans = tmp;
		file = file->next;
	}
	while (ans % 8)
		++ans;
	return (ans);
}

int	com_hl(t_ls_file *file)
{
	int	ans;

	ans = 0;
	while (file)
	{
		if (ans < ft_nbrlen(file->filestat.st_nlink))
			ans = ft_nbrlen(file->filestat.st_nlink);
		file = file->next;
	}
	if (ans < 2)
		return (2);
	return (ans);
}

int	com_owner(t_ls_file *file)
{
	size_t			ans;
	struct passwd	*tmp;

	ans = 0;
	while (file)
	{
		if ((tmp = getpwuid(file->filestat.st_uid)))
			ans = (ans < ft_strlen(tmp->pw_name)) ?
				ft_strlen(tmp->pw_name) : ans;
		else
			ans = (ans < (size_t)ft_nbrlen(file->filestat.st_uid)) ?
				ft_nbrlen(file->filestat.st_uid) : ans;
		file = file->next;
	}
	return (ans);
}

int	com_group(t_ls_file *file)
{
	size_t			ans;
	struct group	*tmp;

	ans = 0;
	while (file)
	{
		if ((tmp = getgrgid(file->filestat.st_gid)))
			ans = (ans < ft_strlen(tmp->gr_name)) ?
				ft_strlen(tmp->gr_name) : ans;
		else
			ans = (ans < (size_t)ft_nbrlen(file->filestat.st_gid)) ?
				ft_nbrlen(file->filestat.st_gid) : ans;
		file = file->next;
	}
	return (ans);
}

int	com_size(t_ls_file *file)
{
	int	ans;

	ans = 0;
	while (file)
	{
		if (ans < ft_nbrlen(file->filestat.st_size))
			ans = ft_nbrlen(file->filestat.st_size);
		file = file->next;
	}
	return (ans);
}

int	com_major(t_ls_file *file)
{
	int			ans;
	int			tmp;

	ans = 0;
	while (file)
	{
		if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
		{
			tmp = file->filestat.st_rdev;
			while ((tmp / 256) > 0)
				tmp /= 256;
			if (ans < ft_nbrlen(tmp))
				ans = ft_nbrlen(tmp);
		}
		file = file->next;
	}
	return (ans);
}

int	com_minor(t_ls_file *file)
{
	int			ans;
	int			tmp;

	ans = 0;
	while (file)
	{
		if (S_ISBLK(file->filestat.st_mode) || S_ISCHR(file->filestat.st_mode))
		{
			tmp = file->filestat.st_rdev;
			tmp %= 256;
			if (ans < ft_nbrlen(tmp))
				ans = ft_nbrlen(tmp);
		}
		file = file->next;
	}
	return (ans);
}
