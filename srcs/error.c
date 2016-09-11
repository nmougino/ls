/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:02:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/12 01:17:31 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_w_param(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n%s\n", c,
		"usage: ft_ls [-FRUaflnrtu] [file ...]");
	return (-1);
}

void	arg_error(char *name)
{
	ft_printf("ft_ls: %s: ", name);
	perror(NULL);
}
