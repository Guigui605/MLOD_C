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
        char toutMonFichierSortie [1000000];//taille max de mon fichier csv : 8 Mo
        int indiceActuel = 0;
        for(int i = 0;i<taille;i++){
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
        toutMonFichierSortie[indiceActuel+1] = '\0';
        long unsigned int tailleDeToutMonFichierSortie = strlen(toutMonFichierSortie);
        char* monFichierSortie = malloc(sizeof(char)*(tailleDeToutMonFichierSortie+1));
        for(int j = 0;j<tailleDeToutMonFichierSortie;j++){
                monFichierSortie[j] = toutMonFichierSortie[j];
        }
        monFichierSortie[tailleDeToutMonFichierSortie-1] = '\0';

        fputs(monFichierSortie, myOutputFile);
        free(monFichierSortie);
        fclose(myOutputFile);
}

unsigned short numberOfWinners(FILE* monFichier){
        rewind(monFichier);
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

void infosAnnee(int annee, gagnantPrixTuring* tousLesGagnants, int taille){
        for(int i = 0;i< taille;i++){
                if(tousLesGagnants[i].annee == annee){
                        printf("\nLe prix Turing de %d a été décerné à %s pour : %s\n",annee, tousLesGagnants[i].gagnant, tousLesGagnants[i].travail);
                        break;
                }
        }
}

void sortTuringWinnersByYear(gagnantPrixTuring* tousLesGagnants, int taille){

        for(int i = 0;i<taille;i++){
                for(int j = 0;j<taille-1;j++){
                        if(tousLesGagnants[j].annee >= tousLesGagnants[j+1].annee){
                                gagnantPrixTuring temp;
                                temp.annee = tousLesGagnants[j].annee;
                                temp.gagnant = tousLesGagnants[j].gagnant;
                                temp.travail = tousLesGagnants[j].travail;

                                tousLesGagnants[j].annee = tousLesGagnants[j+1].annee;
                                tousLesGagnants[j].gagnant = tousLesGagnants[j+1].gagnant;
                                tousLesGagnants[j].travail = tousLesGagnants[j+1].travail;

                                tousLesGagnants[j+1].annee = temp.annee;
                                tousLesGagnants[j+1].gagnant = temp.gagnant;
                                tousLesGagnants[j+1].travail = temp.travail;

                        }
                }
        }
}

int main(int argc, char** argv) {
        //a chaque fois un paramètre avec - pour dire de quel type de paramètre il s'agit, et le paramètre suivant qui est le paramètre de l'action correspondante.
	char filename[] = "turingWinners.csv";
        char* outputFilename = NULL;
        FILE * fileCsv = fopen(filename,"r");
        int taille = numberOfWinners(fileCsv);
        rewind (fileCsv);
        gagnantPrixTuring* tousLesGagnants = readWinners(fileCsv, taille);

        int freeOutputName = 1;
        int optionRename = 0;

        for(int i = 1;i<argc;i++){
                char optionO [] = "-o";
                char optionInfo[] = "--info";
                char optionSort[] = "--sort";

                int optO = 1;
                int optInfo = 1;
                int optSort = 1;

                for(int j = 0; j<strlen(argv[i]); j++){
                        if(j<=strlen(optionO) && optO!=0 && argv[i][j] != optionO[j]){
                                optO = 0;
                        }
                        if(j<=strlen(optionInfo) && optInfo!=0 && argv[i][j] != optionInfo[j]){
                                optInfo = 0;
                        }
                        if(j<=strlen(optionSort) && optSort!=0 && argv[i][j] != optionSort[j]){
                                optSort = 0;
                        }
                }

                if(optO==1){
                        optionRename = 1;
                        rename(filename,argv[i+1]);
                        if(argc >= i+1 &&*argv[i+2] != '-'){
                                outputFilename = argv[i+2];
                                freeOutputName = 0;
                        }
                        else{
                                outputFilename = malloc(sizeof(char)*8);
                                strcpy(outputFilename, "out.csv\0");
                        }
                        i++;
                }
                if(optInfo==1){
                        infosAnnee(atoi(argv[i+1]),tousLesGagnants,taille);
                        i++;
                }
                
                if(optSort==1){
                        sortTuringWinnersByYear(tousLesGagnants, taille);
                }
        }
        if(optionRename == 0){
                outputFilename = malloc(sizeof(char)*8);
                strcpy(outputFilename,"out.csv\0");
        }

        printf("nom du fichier d'output : %s\n",outputFilename);
        FILE* outputFile = fopen(outputFilename,"w");
        if(freeOutputName==1){
                free(outputFilename);
        }

        if(outputFile == NULL){
                printf("Pas d'output file\n");
        }

        printWinner(tousLesGagnants, outputFile,taille);

        for(int i = 0;i<taille;i++){
                free(tousLesGagnants[i].gagnant);
                free(tousLesGagnants[i].travail);
        }
        free(tousLesGagnants);


        
        //On a finit de récupérer les données du fichier de début.
	return EXIT_SUCCESS;
}
