/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 19:32:58 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/29 13:07:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>

typedef struct	dirent	t_dirent;

void					ft_inspect_file(const char *path);
int						ft_list_dir(const char *filename);

typedef struct			s_meta
{
	char				param;
	int					(*sort_fun)(t_contenu *elem, t_contenu *fst);
	t_contenu			*fst;
}						t_meta;

typedef struct			s_contenu
{
	struct s_contenu	*next;
	struct stat			st_data;
}						t_contenu;

#endif
