/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:25:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/10 23:37:07 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	disp_arg(t_ls_file *fil, t_ls_file *dir, t_ls_meta *meta, int ac)
{
	t_ls_file	*cur;

	if (fil)
		display(fil, meta);
	cur = dir;
	if (fil && cur)
		write(1, "\n", 1);
	while (cur)
	{
		if (ac > 1)
		{
			ft_putstr(cur->path);
			write(1, ":\n", 2);
		}
		if (meta->param & (1 << 4))
			ls_rec(meta, cur->path);
		else
			ls_std(meta, cur->path);
		cur->next ? write(1, "\n", 1) : 0;
		cur = cur->next;
	}
}

int		main(int ac, char **av)
{
	t_ls_meta	meta;
	int			i;
	struct stat	buf;
	t_ls_file	*dir;
	t_ls_file	*fil;

	i = 0;
	parser(ac, av, &meta);
	dir = NULL;
	fil = NULL;
	while (i < meta.tarnb)
	{
		if (lstat(meta.target[i], &buf))
			arg_error(meta.target[i]);
		else
			ls_add_file(meta.target[i], NULL,
				((S_ISDIR(buf.st_mode)) ? &dir : &fil), &meta);
		++i;
	}
	disp_arg(fil, dir, &meta, meta.tarnb);
	free_file(fil);
	free_file(dir);
	free_meta(&meta);
	return (0);
}
