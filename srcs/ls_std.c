/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 21:18:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/14 13:00:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_std(t_ls_meta *meta, const char *path)
{
	t_ls_file	*list;

	errno = 0;
	if ((list = ls_list_dir(path, meta)))
	{
		display(&list, meta);
		free_file(list);
	}
	else if (errno)
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
}
