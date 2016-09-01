/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:33:39 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 19:22:47 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	long_display(fichier)
{
	disp_mode(fichier);		// 1
	disp_hl(fichier);		// 2
	disp_owner(fichier);	// 3
	disp_group(fichier);	// 4
	disp_size(fichier);		// 5
	disp_time(fichier);		// 6
	disp_name(fichier);		// 7
}

/*

format l :

>    1     |2 |   3    ||    4     ||  5 |     6      | 7
drwxr-xr-x  10 nmougino  2015_paris  4096 Aug 24 13:51 nfs
dr-xr-xr-x@  2 root      wheel         68 Oct  6  2015 net

	b     Block special file.
	c     Character special file.
	d     Directory.
	l     Symbolic link.
	s     Socket link.
	p     FIFO.
	-     Regular file.

owner/group/other

	The next three fields are three characters each: owner permissions, group
	permissions, and other permissions.  Each field has three character posi-
	tions:

           1.   If r, the file is readable; if -, it is not readable.
           2.   If w, the file is writable; if -, it is not writable.
           3.   The first of the following that applies:

                      S     If in the owner permissions, the file is not exe-
                            cutable and set-user-ID mode is set.  If in the
                            group permissions, the file is not executable and
                            set-group-ID mode is set.

                      s     If in the owner permissions, the file is exe-
                            cutable and set-user-ID mode is set.  If in the
                            group permissions, the file is executable and set-
                            group-ID mode is set.

                      x     The file is executable or the directory is search-
                            able.

                      -     The file is neither readable, writable, exe-
                            cutable, nor set-user-ID nor set-group-ID mode,
                            nor sticky.  (See below.)

                These next two apply only to the third character in the last
                group (other permissions).

                      T     The sticky bit is set (mode 1000), but not execute
                            or search permission.  (See chmod(1) or
                            sticky(8).)

                      t     The sticky bit is set (mode 1000), and is search-
                            able or executable.  (See chmod(1) or sticky(8).)

If the file or directory has extended
attributes, the permissions field printed by the -l option is followed by
a '@' character.  Otherwise, if the file or directory has extended secu-
rity information (such as an access control list), the permissions field
printed by the -l option is followed by a '+' character.

Nombre de hard links

owner
group
taille (byte)
derniere date d'acces (si anterieur a 6 mois : MDY si posterieur : MDH)
Nom
-> link si link

*/
