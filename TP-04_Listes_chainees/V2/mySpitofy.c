#include "linkedListOfMusic.h"

int numberOfLines(FILE* file){
    if(file == NULL){
        return 0;
    }
    rewind(file);
    int compteur = 0;
    while(!feof(file)){
        if(fgetc(file)=='\n'){
            compteur++;
        }
    }
    return compteur;
}

Music* fileReader(FILE* file,int nbLines){
    rewind(file);
    char line[2048];
    Music* toutesLesMusiques = malloc(sizeof(Music)*nbLines);
    for(int i = 0;i<nbLines;i++){
        fgets(line,2047,file);
        readLine(&toutesLesMusiques[i])
    }
}

int main(void){
    char* fileName ="music.csv";

    FILE* musicFile = fopen(fileName,"r");


}