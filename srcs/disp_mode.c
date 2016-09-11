/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 11:16:50 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 01:40:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	disp_mode_type(mode_t mode)
{
	if (S_ISLNK(mode))
		write(1, "l", 1);
	else if (S_ISBLK(mode))
		write(1, "b", 1);
	else if (S_ISDIR(mode))
		write(1, "d", 1);
	else if (S_ISCHR(mode))
		write(1, "c", 1);
	else if (S_ISFIFO(mode))
		write(1, "f", 1);
	else if (S_ISSOCK(mode))
		write(1, "s", 1);
	else if (S_ISREG(mode))
		write(1, "-", 1);
	else
		write(1, "u", 1);
}

void	disp_mode_owner(mode_t mode)
{
	write(1, (mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (mode & S_IWUSR) ? "w" : "-", 1);
	if (mode & S_IXUSR && mode & S_ISUID)
		write(1, "s", 1);
	else if (mode & S_IXUSR)
		write(1, "x", 1);
	else if (mode & S_ISUID)
		write(1, "S", 1);
	else
		write(1, "-", 1);
}

void	disp_mode_group(mode_t mode)
{
	write(1, (mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (mode & S_IWGRP) ? "w" : "-", 1);
	if (mode & S_IXGRP && mode & S_ISGID)
		write(1, "s", 1);
	else if (mode & S_IXGRP)
		write(1, "x", 1);
	else if (mode & S_ISGID)
		write(1, "S", 1);
	else
		write(1, "-", 1);
}

void	disp_mode_other(mode_t mode)
{
	write(1, (mode & S_IROTH) ? "r" : "-", 1);
	write(1, (mode & S_IWOTH) ? "w" : "-", 1);
	if (mode & S_IXOTH && mode & S_ISVTX)
		write(1, "t", 1);
	else if (mode & S_IXOTH)
		write(1, "x", 1);
	else if (mode & S_ISVTX)
		write(1, "T", 1);
	else
		write(1, "-", 1);
}

void	disp_p(mode_t mode, int param)
{
	if ((!(param & (1 << 6))) && S_ISDIR(mode))
		write(1, "/", 1);
}
