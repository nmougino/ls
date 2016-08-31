/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 02:02:37 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/31 02:06:15 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		error_w_param(char c)
{
	ft_printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", c);
	return (-1);
}
