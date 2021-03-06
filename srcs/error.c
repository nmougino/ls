/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:02:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 23:04:16 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_w_param(char c)
{
	ft_dprintf(2, "ft_ls: illegal option -- %c\n%s\n", c,
		"usage: ft_ls [-FRUacflnprtu] [file ...]");
	return (-1);
}

void	arg_error(char *name)
{
	ft_dprintf(2, "ft_ls: %s: ", name);
	perror(NULL);
}
