#include "linkedList.h"

struct music{
    char* name;
    char* artist;
    char* album;
    char* genre;
    unsigned short discNumber;
    unsigned short trackNumber;
    unsigned short year;
}Music;



void afficheElement(Music* m){
    printf("Name : %s\nArtist : %s\nAlbum : %s\nGenre : %s\nDisc number : %i\nTrack number : %i\nYear : %i\n",m->name,m->artist,m->album,m->genre,m->discNumber,m->trackNumber,m->year);
}

void detruireElement(Music* m){
    free(m->name);
    free(m->artist);
    free(m->album);
    free(m->genre);
    free(m);
}

bool equalsElement(Music* m1,Music* m2){
    return m1->name == m2->name && m1->artist == m2->artist && m1->album == m2->album && m1->genre == m2->genre && m1->discNumber == m2->discNumber && m1->trackNumber == m2->trackNumber && m1->year == m2->year;
}