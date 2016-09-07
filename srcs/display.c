/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:36:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 21:54:52 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls_file *file)
{
	while (file)
	{
		ft_putendl(file->dp.d_name);
		file = file->next;
	}
}
