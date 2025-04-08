#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void printList(Node* head) {
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}  

void adaugaNod(Node** head, int el) {
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(!new_node) {
        perror("Eroare aloc mem la nod!\n");
        exit(-1);
    }
    new_node->data = el;
    new_node->next = *head;
    *head = new_node;
}

void delNod(Node* head, int el) {
    if(!head) {
        printf("lista este goala\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    if(temp != NULL && temp->data == el) {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != el) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("El nu a fost gasit\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void freeList(Node* head) {
    while(head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main(void) {
    Node* head = NULL;
    adaugaNod(&head, 2);
    adaugaNod(&head, 1);
    adaugaNod(&head, 3);

    printList(head);

    Node* rev = reverseList(head);

    printList(rev);

    freeList(head);
    return 0;
}