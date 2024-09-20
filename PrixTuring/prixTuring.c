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

void ecrireLigneDansStruct(char* maLigne, gagnantPrixTuring unGagnant){
        int cpt = 0;
        char annee[4];
        while (maLigne[cpt] != ";"){
                annee[cpt] = maLigne[cpt];
                cpt++;
        }
        cpt++;
        int compteurDeCaracteresDansLeNom = 0;
        unGagnant.annee = atoi(annee);
        char nomDuGagnant[500];
        while (maLigne[cpt] != ";"){
                
        }
}

int main(int argc, char** argv)
{
	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

	fileCsv = FILE *fopen(filename,"r");
        char* maLigne = malloc(1024*sizeof(char));
        gagnantPrixTuring tousLesGagnants[200];
        
        for(i=0;;i++){
                if(feof(filename)){
                        break;
                }
                else {
                        char* ptrVersMaLigne = fgets(maLigne, 1023, fileCsv);
                        if(ptrVersMaLigne == NULL){
                                break;
                        }
                        else{
                                ecrireLigneDansStruct(maLigne,tousLesGagnants[i]);
                        }
                }
        }
	


	fclose (fileCsv);

	return EXIT_SUCCESS;
}
