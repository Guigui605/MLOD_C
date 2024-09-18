#include <stdio.h>
#include <stdlib.h>

int* repeat(int t1[], int t2[],int nombreElements){

        int tailleDuTableauResultat = 0;
        for(int i = 0;i<nombreElements;i++){
            tailleDuTableauResultat += t1[i];
        }
        int * tableauResultat = malloc(tailleDuTableauResultat*sizeof(int));
        int compteur = 0;
        for (int i = 0;i<nombreElements;i++){
            for(int j = 0;j<t1[i];j++){
                tableauResultat[compteur] = t2[i];
                compteur++;
            }
        }
        return tableauResultat;
}


void main(void){
    int t1[5] = {1,2,3,4,5};
    int t2[5] = {1,2,3,4,5};
    int* result = repeat(t1,t2,5);
    for (int i = 0;i<15;i++){
        printf("%d\n",result[i]);
    }
    free(result);
}