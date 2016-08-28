/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 19:59:14 by nmougino          #+#    #+#             */
/*   Updated: 2016/08/29 00:07:54 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	inspect_type(struct stat *data)
{
	ft_printf ("Type : ");
    if ((data->st_mode & S_IFBLK) == S_IFBLK)
		ft_printf("périphérique de bloc\n");
    else if ((data->st_mode & S_IFCHR) == S_IFCHR)
		ft_printf("périphérique de caractère\n");
    else if ((data->st_mode & S_IFDIR) == S_IFDIR)
		ft_printf("répertoire\n");
    else if ((data->st_mode & S_IFIFO) == S_IFIFO)
		ft_printf("FIFO/tube\n");
    else if ((data->st_mode & S_IFLNK) == S_IFLNK)
		ft_printf("lien symbolique\n");
    else if ((data->st_mode & S_IFREG) == S_IFREG)
		ft_printf("fichier ordinaire\n");
    else if ((data->st_mode & S_IFSOCK) == S_IFSOCK)
		ft_printf("socket\n");
	else
		ft_printf("INCONNU -> %d\n", data->st_mode);
	ft_printf("statut d'un repertoire : %d\n", S_IFDIR);
}

void	ft_inspect_file(const char *path)
{
	struct stat	data;

	ft_printf("lecture : %d\n", stat(path, &data));
	inspect_type(&data);
	ft_printf("Numéro d'inœud : %ld\n", (long) data.st_ino);
	ft_printf("Dernier changement d’état : %s", ctime(&data.st_ctime));
    ft_printf("Dernier accès au fichier : %s", ctime(&data.st_atime));
    ft_printf("Dernière modification du fichier: %s", ctime(&data.st_mtime));
	ft_printf("Propriétaires :\tUID=%ld\tGID=%ld\n", (long) data.st_uid, (long) data.st_gid);

}

//struct stat { /* when _DARWIN_FEATURE_64_BIT_INODE is defined */
//         dev_t           st_dev;           /* ID of device containing file */
//         mode_t          st_mode;          /* Mode of file (see below) */
//         nlink_t         st_nlink;         /* Number of hard links */
//         ino_t           st_ino;           /* File serial number */
//         uid_t           st_uid;           /* User ID of the file */
//         gid_t           st_gid;           /* Group ID of the file */
//         dev_t           st_rdev;          /* Device ID */
//         struct timespec st_atimespec;     /* time of last access */
//         struct timespec st_mtimespec;     /* time of last data modification */
//         struct timespec st_ctimespec;     /* time of last status change */
//         struct timespec st_birthtimespec; /* time of file creation(birth) */
//         off_t           st_size;          /* file size, in bytes */
//         blkcnt_t        st_blocks;        /* blocks allocated for file */
//         blksize_t       st_blksize;       /* optimal blocksize for I/O */
//         uint32_t        st_flags;         /* user defined flags for file */
//         uint32_t        st_gen;           /* file generation number */
//         int32_t         st_lspare;        /* RESERVED: DO NOT USE! */
//         int64_t         st_qspare[2];     /* RESERVED: DO NOT USE! */
//     };
