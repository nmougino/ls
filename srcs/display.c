/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:36:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 00:29:25 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls_file **file, t_ls_meta *meta)
{
	t_ls_file	*tmp;

	tmp = *file;
	if (meta->param & (1 << 2) || meta->param & (1 << 5))
		long_display(file, meta->param);
	else
	{
		while (tmp)
		{
			ft_putstr(tmp->dp.d_name);
			(meta->param & (1 << 6)) ? disp_mf(tmp->filestat.st_mode) : 0;
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
}
