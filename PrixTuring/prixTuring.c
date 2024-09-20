/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring

 Tests
 diff out.csv turingWinners.csv

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define LIGNE_MAX 600;
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

typedef struct {
	int annee;
	char* gagnant;
	char* travail;
} gagnantPrixTuring;

void printWinner(gagnantPrixTuring tableauDeGagnants[], FILE* myOutputFile){
        char toutMonFichierSortie [10000000];//taille max de mon fichier csv : 80 Mo
        int indiceActuel = 0;
        int i = 0;
        while (tableauDeGagnants[i].annee > 1900 && tableauDeGagnants[i].annee < 2050){
                char monAnnee[5];
                sprintf(monAnnee, "%d", tableauDeGagnants[i].annee);
                for(int j = 0;j<4;j++){
                        toutMonFichierSortie[indiceActuel] = monAnnee[j];
                        indiceActuel++;
                }
                toutMonFichierSortie[indiceActuel] = ';';
                indiceActuel++;
                int tailleNom = strlen(tableauDeGagnants[i].gagnant);
                for(int j = 0;j<tailleNom;j++){
                        toutMonFichierSortie[indiceActuel] = tableauDeGagnants[i].gagnant[j];
                        indiceActuel++;
                }
                toutMonFichierSortie[indiceActuel] = ';';
                indiceActuel++;
                int tailleTravail = strlen(tableauDeGagnants[i].travail);
                for(int j = 0;j<tailleTravail;j++){
                        toutMonFichierSortie[indiceActuel] = tableauDeGagnants[i].travail[j];
                        indiceActuel++;
                }
                toutMonFichierSortie[indiceActuel] = '\n';
                indiceActuel++;
                i++;
        }
        toutMonFichierSortie[indiceActuel] = '\0';
        long unsigned int tailleDeToutMonFichierSortie = strlen(toutMonFichierSortie);
        char* monFichierSortie = malloc(sizeof(char)*(tailleDeToutMonFichierSortie+1));
        for(int j = 0;j<tailleDeToutMonFichierSortie;j++){
                monFichierSortie[j] = toutMonFichierSortie[j];
        }
        monFichierSortie[tailleDeToutMonFichierSortie] = '\0';
}

unsigned short numberOfWinners(FILE monFichier){
        rewind(monFichier);
        char maLigne[2048];
        int cpt=0;
        for(;;){
                char* ligne = fgets(maLigne, 2047,monFichier);
                if(ligne == NULL){
                        return cpt;
                }
        }
}

void readWinner(char* maLigne, gagnantPrixTuring* unGagnant){
        int cpt = 0;
        char annee[4];
        while (maLigne[cpt] != ';'){
                annee[cpt] = maLigne[cpt];
                cpt++;
        }
        cpt++;
        int compteurDeCaracteresDansLeNom = 0;
        unGagnant -> annee = atoi(annee);
        char nomDuGagnant[500];
        while (maLigne[cpt] != ';'){
                nomDuGagnant[compteurDeCaracteresDansLeNom] = maLigne[cpt];
                compteurDeCaracteresDansLeNom++;
                cpt++;
        }
        compteurDeCaracteresDansLeNom++;
        cpt++;
        nomDuGagnant[compteurDeCaracteresDansLeNom] = '\0';
        unGagnant -> gagnant = malloc((strlen(nomDuGagnant)+1)*sizeof(char));
        for(int i = 0;i<strlen(nomDuGagnant)+1;i++){
                unGagnant -> gagnant[i] = nomDuGagnant[i];
        }
        int compteurDeCaracteresDansTravail = 0;
        char travail[2047];
        while (maLigne[cpt] != '\n'){
                travail[compteurDeCaracteresDansTravail] = maLigne[cpt];
                compteurDeCaracteresDansTravail++;
                cpt++;
        }
        compteurDeCaracteresDansTravail++;
        travail[compteurDeCaracteresDansTravail] = '\0';
        unGagnant -> travail = malloc((strlen(travail)+1)*sizeof(char));
        for(int i = 0;i<strlen(travail)+1;i++){
                unGagnant -> travail[i] = travail[i];
        }
}

gagnantPrixTuring* readWinners(FILE* monFichier, gagnantPrixTuring* tousLesGagnants, int nombreDeGagnants){
        rewind(monFichier);

}

int main(int argc, char** argv) {
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE * fileCsv = fopen(filename,"r");
        char* maLigne = malloc(2048*sizeof(char));
        int taille = nbOfWinners(fileCsv);
        rewind (fileCsv);
        gagnantPrixTuring tousLesGagnants[200];
        
        for(int i=0;;i++){
                if(feof(fileCsv)){
                        tousLesGagnants = realloc((i+1)*sizeof(gagnantPrixTuring));
                        break;
                }
                else {
                        char* ptrVersMaLigne = fgets(maLigne, 2047, fileCsv);
                        if(ptrVersMaLigne == NULL){
                                break;
                        }
                        else{
                                readWinners(maLigne,&(tousLesGagnants[i]));
                        }
                }
        }
	fclose (fileCsv);
        //On a finit de récupérer les données du fichier de début.
	return EXIT_SUCCESS;
}
