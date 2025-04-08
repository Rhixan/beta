#include <stdio.h>
#include <stdlib.h>

#include "el_t.h"

struct KVS_t {
    El_t* elemente;
    size_t size;
    size_t capacity;
};

KVS_t* adauga(KVS_t* v, El_t el) {
    if (v == NULL) {
        v = malloc(sizeof(KVS_t));
        v->capacity = 10;
        v->elemente = malloc(v->capacity * sizeof(El_t));
        v->size = 0;
    }

    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->elemente = realloc(v->elemente, v->capacity * sizeof(El_t));
    }

    v->elemente[v->size] = el;
    v->size ++;

    return v;
}

void printKVS(KVS_t* v) {
    if (v == NULL) {
        fprintf(stderr, "Tabloul este gol!\n");
        exit(-1);        
    }
    for(size_t i = 0; i < v->size; i++) {
        printf("cheie: %llu, Valoare: %2f\n", v->elemente[i].cheie, v->elemente[i].valoare);
    }
}

int cauta(KVS_t* v, unsigned k) {
    if (v == NULL) {
        fprintf(stderr, "Tabloul este gol!\n");
        exit(-1);        
    }

    for ( size_t i = 0; i < v->size; i++) {
        if (v->elemente[i].cheie == k) {
            return i;
        }
    }
    return -1;
}