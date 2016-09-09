/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 04:08:02 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 10:47:35 by nmougino         ###   ########.fr       */
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
	if (mode & S_IXGRP && mode & S_ISVTX)
		write(1, "t", 1);
	else if (mode & S_IXGRP)
		write(1, "x", 1);
	else if (mode & S_ISVTX)
		write(1, "T", 1);
	else
		write(1, "-", 1);
}

void	disp_acl(void)
{
	write(1, " ", 1);
}

char	*disp_owner(uid_t uid)
{
	struct passwd	*tmp;

	if (!(tmp = getpwuid(uid)))
		return (ft_itoa(uid));
	else
		return (ft_strdup(tmp->pw_name));
}

char	*disp_group(gid_t gid)
{
	struct group	*tmp;

	if (!(tmp = getgrgid(gid)))
		return (ft_itoa(gid));
	else
		return (ft_strdup(tmp->gr_name));
}

char	*disp_time(time_t tmp)
{
	double	timediff;

	timediff = time(NULL) - tmp;
	if ((timediff > 15778800) || (timediff < -15778800))
		return (ctime(&tmp) + 19);
	return (ctime(&tmp) + 11);
}

void	disp_link_target(char *path)
{
	char buf[1024];

	ft_bzero(buf, 1024);
	readlink(path, buf, 1024);
	ft_printf(" -> %s", buf);
}

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
//In addition, for each directory whose contents are displayed, the total number of 512-byte
//blocks used by the files in the directory is displayed on a line by itself, immediately before the information for the files in
//the directory.
void	long_display(t_ls_file *file)
{
	int		col_hl;
	int		col_owner;
	int		col_group;
	int		col_size;
	char	*tmp;

	col_hl = com_hl(file);
	col_owner = com_owner(file);
	col_group = com_group(file);
	col_size = com_size(file);
	ft_printf("total %d\n", disp_block(file));
	//disp_mode_content_size(file);
	while (file)
	{
		disp_mode_type(file->filestat.st_mode);
		disp_mode_owner(file->filestat.st_mode);
		disp_mode_group(file->filestat.st_mode);
		disp_mode_other(file->filestat.st_mode);
		disp_acl();
		ft_printf("%*d %-*s  ", col_hl, file->filestat.st_nlink,
			col_owner, tmp = disp_owner(file->filestat.st_uid));
		free(tmp);
		ft_printf("%-*s  ", col_group, tmp = disp_group(file->filestat.st_gid));
		free(tmp);
		ft_printf("%*d ", col_size, file->filestat.st_size);
		ft_printf("%.7s%.5s ", ctime(&file->filestat.st_mtime) + 4,
					disp_time(file->filestat.st_mtime));
		ft_printf("%s", file->dp.d_name);
		if (S_ISLNK(file->filestat.st_mode))
			disp_link_target(file->path);
		write(1, "\n", 1);
		file = file->next;
	}
}
