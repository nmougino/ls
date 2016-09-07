/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_dep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 22:12:54 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 22:48:31 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		usefull(const char *path)
{
	register int	a;
	register int	n;

	n = ft_strlen(path) - 1;
	a = 0;
	while (path[n] == '.' && a < 3)
	{
		++a;
		--n;
	}
	if (a < 3 && path[n] == '/')
		return (0);
	return (1);
}

char	*add_path(const char *path, const char *new)
{
	const char	*tab[3];

	tab[0] = path;
	tab[1] = new;
	tab[2] = NULL;
	if (path[ft_strlen(path) - 1] == '/')
		return (ft_strglu(tab, -1));
	else
		return (ft_strglu(tab, '/'));
}
