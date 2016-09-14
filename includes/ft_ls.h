/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 19:28:49 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/14 13:26:21 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include <sys/xattr.h>

typedef struct dirent	t_dirent;

typedef struct			s_ls_file
{
	char				*path;
	struct stat			filestat;
	t_dirent			dp;
	int					error;
	struct s_ls_file	*next;
}						t_ls_file;

typedef int				(*t_sortptr)(t_ls_file *, t_ls_file *);

/*
**	param bit map
** -- cpUufFnRalrt
*/

typedef struct			s_ls_meta
{
	int					tarnb;
	char				**target;
	int					param;
	t_sortptr			sortfun;
}						t_ls_meta;

void					arg_error(char *name);
int						error_w_param(char c);

void					check_perm(t_ls_file **fst);

int						parser(int ac, char **av, t_ls_meta *meta);

void					display(t_ls_file **file, t_ls_meta *meta);

void					disp_acl(char *path);

void					disp_mode_type(mode_t mode);
void					disp_mode_owner(mode_t mode);
void					disp_mode_group(mode_t mode);
void					disp_mode_other(mode_t mode);
void					disp_p(mode_t mode, int param);

char					*disp_owner(uid_t uid, int param);
char					*disp_group(gid_t gid, int param);
char					*disp_time(time_t tmp);
void					disp_link_target(char *path);
void					disp_mf(mode_t mode);

void					long_display(t_ls_file **file, int param);

void					free_meta(t_ls_meta *meta);
void					free_file(t_ls_file *fst);

void					ls_add_file(char const *path, t_dirent *dp,
						t_ls_file **file, t_ls_meta *meta);
t_ls_file				*ls_list_dir(char const *path, t_ls_meta *meta);

void					ls_std(t_ls_meta *meta, const char *path);
void					ls_rec(t_ls_meta *meta, const char *path);

int						sort_no(t_ls_file *a, t_ls_file *b);
int						sort_alpha(t_ls_file *a, t_ls_file *b);
int						sort_time(t_ls_file *a, t_ls_file *b);
int						sort_last_access(t_ls_file *a, t_ls_file *b);
int						sort_birth(t_ls_file *a, t_ls_file *b);

int						sort_lstatchg(t_ls_file *a, t_ls_file *b);

int						sort_rev_alpha(t_ls_file *a, t_ls_file *b);
int						sort_rev_time(t_ls_file *a, t_ls_file *b);
int						sort_rev_last_access(t_ls_file *a, t_ls_file *b);
int						sort_rev_birth(t_ls_file *a, t_ls_file *b);
int						sort_rev_lstatchg(t_ls_file *a, t_ls_file *b);

int						usefull(const char *path);
char					*add_path(const char *path, const char *new);

int						com_name(t_ls_file *file);
int						com_hl(t_ls_file *file);
int						com_owner(t_ls_file *file, int param);
int						com_group(t_ls_file *file, int param);
int						com_size(t_ls_file *file);
int						com_major(t_ls_file *file);
int						com_minor(t_ls_file *file);

#endif
