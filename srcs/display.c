/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:36:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/11 20:43:32 by nmougino         ###   ########.fr       */
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
			ft_putendl(tmp->dp.d_name);
			tmp = tmp->next;
		}
	}
}
