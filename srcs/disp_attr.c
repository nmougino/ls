/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_attr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 05:10:59 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/14 13:26:29 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	disp_acl(char *path)
{
	listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		write(1, "@ ", 2);
	else
		write(1, "  ", 2);
}
