/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 17:33:39 by nmougino          #+#    #+#             */
/*   Updated: 2016/09/01 18:15:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

     1     |2 |   3    ||    4     ||  5 |     6      | 7
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
