/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_perm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 18:42:19 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/11 21:53:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			free_one(t_ls_file *f)
{
	free(f->path);
	free(f);
}

static t_ls_file	*extract(t_ls_file *f, t_ls_file *p)
{
	t_ls_file *tmp;

	tmp = f->next;
	if (p)
		p->next = f->next;
	free_one(f);
	return (tmp);
}

static void			check_loop(t_ls_file *file, t_ls_file *tmp)
{
	while (file)
	{
		if (file->error != 0)
		{
			ft_printf("ft_ls: %s: %s\n", file->dp.d_name,
				strerror(file->error));
			file = extract(file, tmp);
		}
		else
		{
			tmp = file;
			file = file->next;
		}
	}
}

void				check_perm(t_ls_file **fst)
{
	t_ls_file	*file;
	t_ls_file	*tmp;

	file = NULL;
	tmp = NULL;
	while (*fst && (*fst)->error != 0)
	{
		tmp = (*fst)->next;
		ft_printf("ft_ls: %s: %s\n", (*fst)->dp.d_name,
		strerror((*fst)->error));
		free_one(*fst);
		*fst = tmp;
	}
	if (*fst)
		file = (*fst)->next;
	check_loop(file, tmp);
}
