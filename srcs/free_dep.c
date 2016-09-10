/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 21:36:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/10 18:23:07 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_meta(t_ls_meta *meta)
{
	if (meta->tarnb)
		while ((meta->tarnb)--)
			free(meta->target[meta->tarnb]);
	free(meta->target);
}

void	free_file(t_ls_file *fst)
{
	t_ls_file	*nxt;

	while (fst)
	{
		nxt = fst->next;
		free(fst->path);
		free(fst);
		fst = nxt;
	}
}
