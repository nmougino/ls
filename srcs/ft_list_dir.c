/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 19:31:31 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/29 02:57:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_list_dir(const char *filename)
{
	DIR			*dir_stream;
	t_dirent	*dir;

	dir_stream = opendir(filename);
	if (!dir_stream)
		return (0);
	while ((dir = readdir(dir_stream)))
		ft_printf("%s\n", dir->d_name);
	closedir(dir_stream);
	return (1);
}
