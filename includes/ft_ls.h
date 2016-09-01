/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:28:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 17:25:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"

typedef struct	s_ls_meta
{
	int			tarnb;
	char		**target;
	//			-- Ralrt
	char		param;
}				t_ls_meta;

int		error_w_param(char c);
int		parser(int ac, char **av, t_ls_meta *meta);

#endif