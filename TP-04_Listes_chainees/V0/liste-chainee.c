#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste nvListe;
	nvListe = malloc(sizeof(Cellule));
	nvListe->val = v;
	nvListe->suiv = NULL;
	return nvListe;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste nvElement = creer(v);
	nvElement->suiv = l;
	return nvElement;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Cellule* elementActuel = l;
	while (elementActuel != NULL){
		afficheElement(elementActuel->val);
		elementActuel = elementActuel -> suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	if(l != NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
	printf("\n");
}

void detruireElement(Element e) {
	e = 0;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Cellule* elementActuel = l;
	while(elementActuel != NULL){
		detruireElement(elementActuel->val);
		l = elementActuel->suiv;
		free(elementActuel);
		elementActuel = NULL;
	}
}

// version récursive
void detruire_r(Liste l) {
	if(l!=NULL){
		detruire_r(l->suiv);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste nvElement = creer(v);
	Liste elementActuel = l;
	while(elementActuel->suiv != NULL){
		elementActuel = elementActuel->suiv;
	}
	elementActuel->suiv = nvElement;
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l->suiv == NULL){
		Liste nvElement = creer(v);
		l->suiv = nvElement;
		return l;
	}
	else{
		ajoutFin_r(v,l->suiv);
		return l;
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste elementActuel = l;
	while (elementActuel->val != v ){
		if(elementActuel->suiv == NULL)
			return NULL;
		else
			elementActuel = elementActuel->suiv;
	}
	return elementActuel;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l->val == v){
		return l;
	}
	else if(l->suiv ==NULL){
		return NULL;
	}
	else{
		return cherche_r(v,l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	if(l==NULL){
		return l;
	}
	Liste elementActuel = l;
	Liste elementSuivant = l->suiv;
	if(elementActuel->val == v){
		return elementSuivant;
	}else if(elementSuivant == NULL){
		return l;
	}
	while(elementSuivant->val != v){
		if(elementSuivant->suiv == NULL){
			return l;
		}
		else{
			elementActuel = elementSuivant;
			elementSuivant = elementActuel->suiv;
		}
	}
	elementActuel->suiv = elementSuivant->suiv;
	detruireElement(elementSuivant->val);
	free(elementSuivant);
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(l==NULL){
		return l;
	}
	else if(l->val == v){
		Liste suivant = l->suiv;
		free(l);
		return suivant;
	}
	else{
		l->suiv = retirePremier_r(v,l->suiv);
	}
	return l;
}


void afficheEnvers_r(Liste l) {
	if(l==NULL){}
	else if(l->suiv ==NULL){
		afficheElement(l->val);
	}
	else{
		afficheEnvers_r(l->suiv);
		afficheElement(l->val);
	}
}



