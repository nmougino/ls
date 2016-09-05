/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 21:18:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/05 22:07:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_std(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;

	list = list_dir(path);
	display(list);
	file_free(list);
}
