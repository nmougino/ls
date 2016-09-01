/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:23:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 23:05:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//The status information word st_mode has the following bits:
//
//     #define S_IFMT   0170000  /* type of file */
//     #define S_IFIFO  0010000  /* named pipe (fifo) */
//     #define S_IFCHR  0020000  /* character special */
//     #define S_IFDIR  0040000  /* directory */
//     #define S_IFBLK  0060000  /* block special */
//     #define S_IFREG  0100000  /* regular */
//     #define S_IFLNK  0120000  /* symbolic link */
//     #define S_IFSOCK 0140000  /* socket */
//     #define S_IFWHT  0160000  /* whiteout */
//     #define S_ISUID  0004000  /* set user id on execution */
//     #define S_ISGID  0002000  /* set group id on execution */
//     #define S_ISVTX  0001000  /* save swapped text even after use */
//     #define S_IRUSR  0000400  /* read permission, owner */
//     #define S_IWUSR  0000200  /* write permission, owner */
//     #define S_IXUSR  0000100  /* execute/search permission, owner */

//		S_IFMT		0170000		masque du type de fichier
//		S_IFSOCK	0140000		socket
//		S_IFLNK		0120000		lien symbolique
//		S_IFREG		0100000		fichier ordinaire
//		S_IFBLK		0060000		périphérique blocs
//		S_IFDIR		0040000		répertoire
//		S_IFCHR		0020000		périphérique caractères
//		S_IFIFO		0010000		fifo
//		S_ISUID		0004000		bit set-UID
//		S_ISGID		0002000		bit set-GID (voir plus loin)
//		S_ISVTX		0001000		bit « sticky » (voir plus loin)
//		S_IRWXU		00700		lecture/écriture/exécution du propriétaire
//		S_IRUSR		00400		le propriétaire a le droit de lecture
//		S_IWUSR		00200		le propriétaire a le droit d'écriture
//		S_IXUSR		00100		le propriétaire a le droit d'exécution
//		S_IRWXG		00070		lecture/écriture/exécution du groupe
//		S_IRGRP		00040		le groupe a le droit de lecture
//		S_IWGRP		00020		le groupe a le droit d'écriture
//		S_IXGRP		00010		le groupe a le droit d'exécution
//		S_IRWXO		00007		lecture/écriture/exécution des autres
//		S_IROTH		00004		les autres ont le droit de lecture
//		S_IWOTH		00002		les autres ont le droit d'écriture
//		S_IXOTH		00001		les autres ont le droit d'exécution

/*

	premier c:
	b     Block special file.
	c     Character special file.
	d     Directory.
	l     Symbolic link.
	s     Socket link.
	p     FIFO.
	-     Regular file.

*/

#include "ft_ls.h"

void	disp_mode_type(mode_t mode)
{
	// quel est l'ordre de priorite
	// le b repond dans tous les cas
	// et l aussi...
	// apparement je ne sais pas m'en servir...
	if (mode & S_IFDIR)
		write(1, "d", 1);
	else if (mode & S_IFLNK)
		write(1, "l", 1);
	else if (mode & S_IFBLK)
		write(1, "b", 1);
	else if (mode & S_IFCHR)
		write(1, "c", 1);
	else if (mode & S_IFIFO)
		write(1, "p", 1);
	else
		write(1, "-", 1);
	// et s ???
}

void	disp_mode_owner(mode_t mode)
{
	write(1, (mode & S_IRUSR) ? "r" : "-", 1);
	write(1, (mode & S_IWUSR) ? "w" : "-", 1);
	if (mode & S_IXUSR && mode & S_ISUID)
		write(1, "s", 1);
	else if (mode & S_IXUSR)
		write(1, "x", 1);
	else if (mode & S_ISUID)
		write(1, "S", 1);
	else
		write(1, "-", 1);
}

void	disp_mode_group(mode_t mode)
{
	write(1, (mode & S_IRGRP) ? "r" : "-", 1);
	write(1, (mode & S_IWGRP) ? "w" : "-", 1);
	if (mode & S_IXGRP && mode & S_ISGID)
		write(1, "s", 1);
	else if (mode & S_IXGRP)
		write(1, "x", 1);
	else if (mode & S_ISGID)
		write(1, "S", 1);
	else
		write(1, "-", 1);
}

void	disp_mode_other(mode_t mode)
{
	write(1, (mode & S_IROTH) ? "r" : "-", 1);
	write(1, (mode & S_IWOTH) ? "w" : "-", 1);
	if (mode & S_IXGRP && mode & S_ISVTX)
		write(1, "t", 1);
	else if (mode & S_IXGRP)
		write(1, "x", 1);
	else if (mode & S_ISVTX)
		write(1, "T", 1);
	else
		write(1, "-", 1);
}

void	disp_mode(mode_t mode)
{
	disp_mode_type(mode);
	disp_mode_owner(mode);
	disp_mode_group(mode);
	disp_mode_other(mode);
	// disp_mode_extend();
	// comment detecter les modes etendus de securite et autres?
}

// V1 a etudier:

/*
void	disp_mode(mode_t mode)
{


	if (mode & S_IFSOCK)
		ft_printf("socket\n");
	if (mode & S_IFLNK)
		ft_printf("lien symbolique\n");
	if (mode & S_IFREG)
		ft_printf("fichier ordinaire\n");
	if (mode & S_IFBLK)
		ft_printf("périphérique blocs\n");
	if (mode & S_IFDIR)
		ft_printf("répertoire\n");
	if (mode & S_IFCHR)
		ft_printf("périphérique caractères\n");
	if (mode & S_IFIFO)
		ft_printf("fifo\n");
	if (mode & S_ISUID)
		ft_printf("bit set-UID\n");
	if (mode & S_ISGID)
		ft_printf("bit set-GID (voir plus loin)\n");
	if (mode & S_ISVTX)
		ft_printf("bit « sticky » (voir plus loin)\n");
	if (mode & S_IRUSR)
		ft_printf("le propriétaire a le droit de lecture\n");
	if (mode & S_IWUSR)
		ft_printf("le propriétaire a le droit d'écriture\n");
	if (mode & S_IXUSR)
		ft_printf("le propriétaire a le droit d'exécution\n");
	if (mode & S_IRGRP)
		ft_printf("le groupe a le droit de lecture\n");
	if (mode & S_IWGRP)
		ft_printf("le groupe a le droit d'écriture\n");
	if (mode & S_IXGRP)
		ft_printf("le groupe a le droit d'exécution\n");
	if (mode & S_IROTH)
		ft_printf("les autres ont le droit de lecture\n");
	if (mode & S_IWOTH)
		ft_printf("les autres ont le droit d'écriture\n");
	if (mode & S_IXOTH)
		ft_printf("les autres ont le droit d'exécution\n");
}
*/
