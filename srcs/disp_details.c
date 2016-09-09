/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_details.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 11:20:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/09 11:20:23 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*disp_owner(uid_t uid)
{
	struct passwd	*tmp;

	if (!(tmp = getpwuid(uid)))
		return (ft_itoa(uid));
	else
		return (ft_strdup(tmp->pw_name));
}

char	*disp_group(gid_t gid)
{
	struct group	*tmp;

	if (!(tmp = getgrgid(gid)))
		return (ft_itoa(gid));
	else
		return (ft_strdup(tmp->gr_name));
}

char	*disp_time(time_t tmp)
{
	double	timediff;

	timediff = time(NULL) - tmp;
	if ((timediff > 15778800) || (timediff < -15778800))
		return (ctime(&tmp) + 19);
	return (ctime(&tmp) + 11);
}

void	disp_link_target(char *path)
{
	char buf[1024];

	ft_bzero(buf, 1024);
	readlink(path, buf, 1024);
	ft_printf(" -> %s", buf);
}
