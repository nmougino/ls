/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:36:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 04:11:42 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls_file *file, t_ls_meta *meta)
{
	if (meta->param & (1 << 2))
		long_display(file);
	else
		while (file)
		{
			ft_putendl(file->dp.d_name);
			file = file->next;
		}
}
