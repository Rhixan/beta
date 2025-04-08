#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

Stack_t* creare_stiva(int capacitate) {
    Stack_t* stiva = malloc(sizeof(Stack_t));
    if(stiva == NULL) {
        perror("Eroare la alocarea dinamica stivei!\n");
        return NULL;
    }

    stiva -> element = malloc(capacitate * sizeof(Element_t));
    if(stiva -> element == NULL) {
        perror("Eroare la alocarea dinamica a elementelor din stiva!\n");
        free(stiva);
        return NULL;
    }

    stiva -> capacitate = capacitate;
    stiva -> dimensiune = 0;

    return stiva;
}



CodReurn_t adaugare_element(Stack_t* stiva, Element_t valoare) {
    if(stiva -> capacitate <= stiva -> dimensiune) {
        return EROARE_DEPASIRE_LIMITE;
    }

    stiva -> element[stiva -> dimensiune] = valoare;
    stiva -> dimensiune++;
    return OK;
}



Stack_t* adunare_stive(Stack_t* stiva1, Stack_t* stiva2) {

    int max_capacitate = 0;

    if(stiva1 -> capacitate >= stiva2 -> capacitate){
        int max_capacitate = stiva1 -> capacitate;
    }
    else {
        int max_capacitate = stiva2 -> capacitate;
    }

    Stack_t* rezultat = creare_stiva(max_capacitate);

    if(rezultat == NULL) {
        perror("Eroare la crearea stivei rezultat !\n");
        return NULL;
    }

    for(int i = 0; i < max_capacitate; i++){
        Element_t val1 = 0;
        Element_t val2 = 0;

    }
}