/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 06:43:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/14 13:22:37 by nmougino         ###   ########.fr       */
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
	return (ans);
}

int	com_owner(t_ls_file *file, int param)
{
	size_t			ans;
	struct passwd	*tmp;

	ans = 0;
	while (file)
	{
		if ((param & 1 << 5) || !(tmp = getpwuid(file->filestat.st_uid)))
			ans = (ans < (size_t)ft_nbrlen(file->filestat.st_uid)) ?
				ft_nbrlen(file->filestat.st_uid) : ans;
		else
			ans = (ans < ft_strlen(tmp->pw_name)) ?
				ft_strlen(tmp->pw_name) : ans;
		file = file->next;
	}
	return (ans);
}

int	com_group(t_ls_file *file, int param)
{
	size_t			ans;
	struct group	*tmp;

	ans = 0;
	while (file)
	{
		if ((param & 1 << 5) || !(tmp = getgrgid(file->filestat.st_gid)))
			ans = (ans < (size_t)ft_nbrlen(file->filestat.st_gid)) ?
				ft_nbrlen(file->filestat.st_gid) : ans;
		else
			ans = (ans < ft_strlen(tmp->gr_name)) ?
				ft_strlen(tmp->gr_name) : ans;
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
	return (ans < 2 ? 2 : ans);
}
