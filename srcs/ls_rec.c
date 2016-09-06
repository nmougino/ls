/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 01:28:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/06 01:29:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_rec(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;

	list = ls_list_dir(path, meta);
	display(list);
	free_file(list);
}
