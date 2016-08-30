# ls
Projet pedagogique

Reflexion sur la methode:

liste doublement chainee (et circulaire?) pour traiter le tri facilement.
Attention, la gestion en liste chainee impliquerait des millions de mallocs :O

En recursif cela va considerablement augmenter la necessite d'espace memoire.

La liste chainee reste la meilleure possibilite de stockage des donnees en cache.


Update:
Utiliser lstat afin que dans le cas d'un lien symbolique, on extrait les donnes du lien
et pas du fichier qu'il pointe.
