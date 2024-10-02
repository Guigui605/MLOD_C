#include "linkedList.h"
#include "linkedListOfMusic.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int numberOfLines(FILE* file) {
    if (file == NULL) {
        return 0;
    }
    rewind(file);
    int compteur = 0;
    int c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            compteur++;
        }
    }
    return compteur;
}

void readOneLine(Liste listeMusiques, char line[]){
    
    Music* musiqueAAjouter = malloc(sizeof(Music));

    int cpt = 0;
    char name[100];
    while(line[cpt]!=','){
        name[cpt]=line[cpt];
        cpt++;
    }
    name[cpt]='\0';
    cpt++;
    musiqueAAjouter->name = malloc(sizeof(char)*(strlen(name)+1));
    for(int i = 0;i<strlen(name)+1;i++){
        musiqueAAjouter->name[i] = name[i];
    }
    char artist[150];
    int cpt2 = 0;
    while(line[cpt] != ','){
        artist[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    artist[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->artist = malloc(sizeof(char)*(strlen(artist)+1));
    for(int i = 0;i<strlen(artist)+1;i++){
        musiqueAAjouter->artist[i] = artist[i];
    }
    char album[150];
    cpt2 = 0;
    while(line[cpt] != ','){
        album[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    album[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->album = malloc(sizeof(char)*(strlen(album)+1));
    for(int i = 0;i<strlen(album)+1;i++){
        musiqueAAjouter->album[i] = album[i];
    }
    char genre[150];
    cpt2 = 0;
    while(line[cpt] != ','){
        genre[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    genre[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->genre = malloc(sizeof(char)*(strlen(genre)+1));
    for(int i = 0;i<strlen(genre)+1;i++){
        musiqueAAjouter->genre[i] = genre[i];
    }
    char discNumber[5];
    cpt2 = 0;
    while(line[cpt] != ','){
        discNumber[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    discNumber[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->discNumber = atoi(discNumber);
    char trackNumber[5];
    cpt2 = 0;
    while(line[cpt] != ','){
        trackNumber[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    trackNumber[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->trackNumber = atoi(trackNumber);
    char year[5];
    cpt2 = 0;
    while(line[cpt] != '\n'){
        year[cpt2]=line[cpt];
        cpt++;
        cpt2++;
    }
    year[cpt2] = '\0';
    cpt++;
    musiqueAAjouter->year = atoi(year);
    ajoutFin_i(musiqueAAjouter,listeMusiques);
}

Liste fileReader(FILE* file,int nbLines){
    rewind(file);
    Liste toutesLesMusiques = NULL;
    char line[2048];
    fgets(line,2047,file);//On skip la première ligne car en-têtes
    for(int i = 0;i<nbLines;i++){
        fgets(line,2047,file);
        readOneLine(toutesLesMusiques,line);
    }
    return toutesLesMusiques;
}

int main(void){
    char* fileName ="music.csv";

    FILE* musicFile = fopen(fileName,"r");
    int nbOfLines = numberOfLines(musicFile);
    rewind (musicFile);
    Liste listeDeToutesLesMusiques = fileReader(musicFile,nbOfLines);
    fclose(musicFile);
    Liste copie = listeDeToutesLesMusiques;
    while(listeDeToutesLesMusiques != NULL){
        afficheElement(listeDeToutesLesMusiques->val);
        listeDeToutesLesMusiques = listeDeToutesLesMusiques->suiv;
    }
    
    detruire_i(copie);
    return 0;
}