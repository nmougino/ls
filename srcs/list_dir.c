/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:18:50 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 22:36:37 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_ls_file	*ls_new_file(char const *path, t_dirent *dp)
{
	t_ls_file	*new;
	char		*tpath;

	new = (t_ls_file*)malloc(sizeof(t_ls_file));
	tpath = add_path(path, dp->d_name);
	if (new && (lstat(tpath, &new->filestat) >= 0))
	{
		new->next = NULL;
		ft_memcpy(&new->dp, dp, sizeof(t_dirent));
		new->path = tpath;
	}
	else
		free(tpath);
	return (new);
}

static void			ls_add_file(char const *path, t_dirent *dp, t_ls_file **file, t_ls_meta *meta)
{
	t_ls_file *new;
	t_ls_file *cur;

	new = ls_new_file(path, dp);
	if (!*file)
		*file = new;
	else if (meta->sortfun(new, *file))
	{
		new->next = *file;
		*file = new;
	}
	else
	{
		cur = *file;
		while (cur->next && meta->sortfun(cur->next, new))
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
	}
}

t_ls_file			*ls_list_dir(char const *path, t_ls_meta *meta)
{
	DIR			*dirp;
	t_dirent	*dp;
	t_ls_file	*file;

	file = NULL;
	if (!(dirp = opendir(path)))
		return (NULL);
	while ((dp = readdir(dirp)))
	{
		if (!(dp->d_name[0] == '.' && !(meta->param & (1 << 3))))
			ls_add_file(path, dp, &file, meta);
	}
	(void)closedir(dirp);
	return (file);
}