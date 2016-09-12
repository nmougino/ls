/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 05:10:59 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 05:54:43 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		com_acl(t_ls_file *file)
{
	char attr[256];

	while (file)
	{
		ft_bzero(attr, 256);
		listxattr(file->path, attr, 255, XATTR_NOFOLLOW);
		if (ft_strlen(attr) > 0)
			return (1);
		file = file->next;
	}
	return (0);
}

void	disp_acl(char *path, int col)
{
	char attr[256];

	ft_bzero(attr, 256);
	listxattr(path, attr, 255, XATTR_NOFOLLOW);
	if (ft_strlen(attr) > 0)
		write(1, "@", 1);
	else
		write(1, " ", 1);
	if (col)
		write(1, " ", 1);
}
