/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 06:43:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 21:10:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	com_name(t_ls_file *file)
{
	register int	ans;
	register int	tmp;

	ans = 0;
	while (file)
	{
		tmp = ft_strlen(file->dp.d_name);
		if (ans < tmp)
			ans = tmp;
		file = file->next;
	}
	while (ans % 8)
		++ans;
	return (ans);
}
