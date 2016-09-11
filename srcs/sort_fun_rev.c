/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 00:36:45 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 00:47:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_rev_alpha(t_ls_file *a, t_ls_file *b)
{
	return (!sort_alpha(a, b));
}

int	sort_rev_time(t_ls_file *a, t_ls_file *b)
{
	return (!sort_time(a, b));
}

int	sort_rev_last_access(t_ls_file *a, t_ls_file *b)
{
	return (!sort_last_access(a, b));
}
