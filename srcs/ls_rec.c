/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:28:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 03:57:54 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ls_rec(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;
	t_ls_file	*cur;

	if ((list = ls_list_dir(path, meta)))
	{
		cur = list;
		display(list, meta);
		while (cur)
		{
			if (S_ISDIR(cur->filestat.st_mode) && usefull(cur->path))
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
	else
		ft_printf("ls: %s: %s\n", path, strerror(errno));
}
