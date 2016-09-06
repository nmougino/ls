/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 23:36:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/06 07:10:49 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display(t_ls_file *file)
{
	register int	col;
	register int	len;

	col = com_name(file);
	while (file)
	{
		len = ft_strlen(file->name);
		write(1, file->name, len);
		if (!(file->next))
			write(1, "\n", 1);
		else
			ft_printf("%*c", col - len, ' ');
		file = file->next;
	}
}
