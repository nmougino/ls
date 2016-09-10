/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:02:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/10 23:25:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_w_param(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n
		usage: ft_ls [-Ralrt] [file ...]\n", c);
	return (-1);
}
