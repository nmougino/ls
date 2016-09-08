/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:28:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/08 18:15:13 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_rec(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;
	t_ls_file	*cur;

	list = ls_list_dir(path, meta);
	cur = list;
	display(list);
	while (cur)
	{
		if (usefull(cur->path) && S_ISDIR(cur->filestat.st_mode))
		{
			write(1, "\n", 1);
			ft_putstr(cur->path);
			write(1, ":\n", 2);
			ls_rec(meta, cur->path);
		}
		cur = cur->next;
	}
	free_file(list);
}
