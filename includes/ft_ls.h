/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:28:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/05 21:41:22 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"
# include <sys/stat.h>

typedef struct			s_ls_meta
{
	int					tarnb;
	char				**target;
	//					-- Ralrt
	char				param;
	int					(*sortfun)(t_ls_file *, t_ls_file *);
}						t_ls_meta;

typedef struct			s_ls_file
{
	char				*name;
	struct stat 		filestat;
	struct s_ls_file	*next;
}						t_ls_file;

typedef struct dirent	t_dirent;

int						error_w_param(char c);
int						parser(int ac, char **av, t_ls_meta *meta);

void					disp_mode(mode_t mode);

void					display(t_ls_file *file);

void					free_meta(t_ls_meta *meta);
void					free_file(t_ls_file *fst);

#endif
