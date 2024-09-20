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

void printWinner(gagnantPrixTuring* tableauDeGagnants, FILE* myOutputFile, int taille){
        printf("Debut de la fonction\n");
        char toutMonFichierSortie [1000000];//taille max de mon fichier csv : 8 Mo
        int indiceActuel = 0;
        printf("taille : %d\n",taille);
        for(int i = 0;i<taille;i++){
                printf("\n %d",i);
                char monAnnee[5];
                sprintf(monAnnee, "%d", tableauDeGagnants[i].annee);
                monAnnee[4] = '\0';
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
        }
        toutMonFichierSortie[indiceActuel] = '\0';
        long unsigned int tailleDeToutMonFichierSortie = strlen(toutMonFichierSortie);
        char* monFichierSortie = malloc(sizeof(char)*(tailleDeToutMonFichierSortie+1));
        for(int j = 0;j<tailleDeToutMonFichierSortie;j++){
                monFichierSortie[j] = toutMonFichierSortie[j];
        }
        monFichierSortie[tailleDeToutMonFichierSortie-1] = '\0';

        fputs(monFichierSortie, myOutputFile);
        fclose(myOutputFile);
}

unsigned short numberOfWinners(FILE* monFichier){
        rewind(monFichier);
        char maLigne[2048];
        int cpt=0;
        for(;;){
                char caractere = fgetc(monFichier);
                if(caractere == '\n') {
                        cpt++;
                }
                else if(caractere == EOF){
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

gagnantPrixTuring* readWinners(FILE* monFichier, int nombreDeGagnants){
        rewind(monFichier);
        char uneLigne[2048];
        gagnantPrixTuring* tousLesGagnants = malloc(nombreDeGagnants*sizeof(gagnantPrixTuring));
        for(int i = 0;i<nombreDeGagnants;i++){
                fgets(uneLigne,2047,monFichier);
                uneLigne[2047]='\0';
                readWinner(uneLigne, &tousLesGagnants[i]);
        }
        fclose(monFichier);
        return tousLesGagnants;
}

int main(int argc, char** argv) {
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	FILE * fileCsv = fopen(filename,"r");
        int taille = numberOfWinners(fileCsv);
        rewind (fileCsv);
        gagnantPrixTuring* tousLesGagnants = readWinners(fileCsv, taille);
        FILE* outputFile = fopen(outputFilename,"w");
        printWinner(tousLesGagnants,outputFile,taille);
        free(tousLesGagnants);


        
        //On a finit de récupérer les données du fichier de début.
	return EXIT_SUCCESS;
}
