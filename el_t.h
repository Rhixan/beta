#ifndef __EL_T_H__
#define __EL_T_H__

typedef struct {
    unsigned long long cheie;
    double valoare;
} El_t;

typedef struct KVS_t KVS_t;

KVS_t* adauga(KVS_t* v, El_t el);
void printKVS(KVS_t* v);
int cauta(KVS_t* v, unsigned k);

#endif