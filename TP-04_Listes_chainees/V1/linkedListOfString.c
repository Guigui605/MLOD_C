#include stdio.h
#include "linkedList.h"

void afficheElement(Element e){
    printf("%c",*e);
}

void detruireElement(Element e){
    e = NULL;
}

bool equalsElement(Element e1, Element e2){
    return *e1 == *e2;
}