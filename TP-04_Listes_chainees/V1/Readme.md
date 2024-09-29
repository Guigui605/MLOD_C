aucun fichier n'est fourni
inspirez-vous largement de la V0


La fonction afficheElement doit etre extern car on ne sait pas quel type afficher, et on ne peut pas le faire sans le type de ce qu'on doit afficher.

La fonction detruireElement doit etre extern car sinon cela peut entrainer des fuites mémoire par exemple. Même si le type de l'élément est void*, on peut free ce pointeur, mais s'il en contient lui-même d'autres, on ne peut pas être au courant à l'avance.

La fonction compareElement doit être extern, car on ne peut pas comparer 2 pointeurs, ça n'a pas de sens de comparer les adresse pour savoir si on parle d'un objet égal, sauf si les 2 objets ont la même adresse (auquel cas c'est un seul objet, bref, ça sert à rien)