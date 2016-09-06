/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 00:18:50 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/06 04:50:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		create_path(char *ptab, char const *path, char *name)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	while(path[i])
	{
		ptab[i] = path[i];
		++i;
	}
	ptab[i] = '/';
	++i;
	while(name[i])
	{
		ptab[i] = name[j];
		++i;
		++j;
	}
}

t_ls_file	*ls_new_file(char const *path, t_dirent *dp)
{
	t_ls_file	*new;
	char		ptab[ft_strlen(path) + dp->d_namlen + 2];

	new = (t_ls_file*)ft_memalloc(sizeof(t_ls_file));
	new->name = ft_strdup(dp->d_name);
	create_path(ptab, path, new->name);
	lstat(ptab, &(new->filestat));
	new->next = NULL;
	return (new);
}

void		ls_add_file(char const *path, t_dirent *dp, t_ls_file **file, t_ls_meta *meta)
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

t_ls_file	*ls_list_dir(char const *path, t_ls_meta *meta)
{
	DIR			*dirp;
	t_dirent	*dp;
	t_ls_file	*file;

	file = NULL;
	if (!(dirp = opendir(path)))
		return (NULL);
	while ((dp = readdir(dirp)))
		ls_add_file(path, dp, &file, meta);
	(void)closedir(dirp);
	return (file);
}
