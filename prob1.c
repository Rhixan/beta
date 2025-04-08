#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "el_t.h"

int main(void) {

    srand(time(NULL));
    KVS_t* colectie = NULL;

    for (int i = 0; i < 5; i++) {
        El_t el;
        el.cheie = rand() % 100;
        el.valoare = rand() % 100;
        colectie = adauga(colectie, el);
    }
    
    printKVS(colectie);

    int pozitie = cauta(colectie, 42);
    if(pozitie != -1) {
        printf("Cheia 42 se afla la pozitia %d\n", pozitie);
    } else {
        printf("Cheia 42 nu exista\n");
    }

    return 0;
}