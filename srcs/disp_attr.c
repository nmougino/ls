/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 05:10:59 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 23:21:52 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		com_acl(t_ls_file *file)
{
	while (file)
	{
		if (listxattr(file->path, NULL, 0, XATTR_NOFOLLOW) > 0)
			return (1);
		file = file->next;
	}
	return (0);
}

void	disp_acl(char *path, int col)
{
	listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		write(1, "@", 1);
	else
		write(1, "  ", 2 - col);
}
