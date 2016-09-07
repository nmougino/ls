/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 02:47:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 21:18:38 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_alpha(t_ls_file *a, t_ls_file *b)
{
	if (!a || !b)
		return (0);
	if (ft_strcmp(a->dp.d_name, b->dp.d_name) < 0)
		return (1);
	else
		return (0);
}
