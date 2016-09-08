/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 21:18:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/06 04:49:24 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_std(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;

	list = ls_list_dir(path, meta);
	display(list);
	free_file(list);
}