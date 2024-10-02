#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char* name;
    char* artist;
    char* album;
    char* genre;
    unsigned short discNumber;
    unsigned short trackNumber;
    unsigned short year;
}Music;




void afficheElement(Element m){
    printf("Name : %s\nArtist : %s\nAlbum : %s\nGenre : %s\nDisc number : %i\nTrack number : %i\nYear : %i\n",((Music*)m)->name,((Music*)m)->artist,((Music*)m)->album,((Music*)m)->genre,((Music*)m)->discNumber,((Music*)m)->trackNumber,((Music*)m)->year);
}

void detruireElement(Element m){
    free(((Music*)m)->name);
    free(((Music*)m)->artist);
    free(((Music*)m)->album);
    free(((Music*)m)->genre);
    free(((Music*)m));
}

bool equalsElement(Element m1,Element m2){
    return ((Music*)m1)->name == ((Music*)m2)->name && ((Music*)m1)->artist == ((Music*)m2)->artist && ((Music*)m1)->album == ((Music*)m2)->album && ((Music*)m1)->genre == ((Music*)m2)->genre && ((Music*)m1)->discNumber == ((Music*)m2)->discNumber && ((Music*)m1)->trackNumber == ((Music*)m2)->trackNumber && ((Music*)m1)->year == ((Music*)m2)->year;
}