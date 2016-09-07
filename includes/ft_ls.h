/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:28:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/07 22:19:20 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>

typedef struct dirent	t_dirent;

typedef struct			s_ls_file
{
	char				*path;
	struct stat 		filestat;
	t_dirent			dp;
	struct s_ls_file	*next;
}						t_ls_file;

typedef struct			s_ls_meta
{
	int					tarnb;
	char				**target;
	//					-- Ralrt
	char				param;
	int					(*sortfun)(t_ls_file *, t_ls_file *);
}						t_ls_meta;

int						error_w_param(char c);
int						parser(int ac, char **av, t_ls_meta *meta);

void					disp_mode(mode_t mode);
void					disp_mode_type(mode_t mode);

void					display(t_ls_file *file);

void					free_meta(t_ls_meta *meta);
void					free_file(t_ls_file *fst);

t_ls_file				*ls_list_dir(char const *path, t_ls_meta *meta);

void					ls_std(t_ls_meta *meta, const char *path);
void					ls_rec(t_ls_meta *meta, const char *path);

int						sort_alpha(t_ls_file *a, t_ls_file *b);

char					*add_path(const char *path, const char *new);

int						com_name(t_ls_file *file);

#endif
