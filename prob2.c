#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

void printList(NODE* head) {
    while(head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

NODE* array2list(int* v, int size) {
    NODE* head = NULL;

    for (int i = size - 1; i >= 0; i--) {
        NODE* node = malloc(sizeof(NODE));
        if (node == NULL) {
            perror("Eroare alocare mem!\n");
            exit(-1);
        }
        node -> data = v[i];
        node -> next = head;
        head = node;
    }

   return head;
}

NODE* reverse_list(NODE* head) {
    NODE* prev = NULL;
    NODE* current = head;
    NODE* next = NULL;
    
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

bool isPalindrome(NODE* head) {
    if(head == NULL || head->next == NULL) {
        return true;
    }

    NODE* slow = head, *fast = head, *prev_slow = NULL;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    };

    NODE* nd_half = reverse_list(slow);
    NODE* st_half = head;

    bool is_pal = true;
    NODE* temp = nd_half;
    
    while(nd_half) {
        if(st_half->data != nd_half->data) {
            is_pal = false;
            break;
        }

        st_half = st_half->next;
        nd_half = nd_half->next;
    }
    reverse_list(temp);
    if(!prev_slow) {
        prev_slow->next = temp;
    }
    return is_pal;
}

void freelist(NODE* head) {
    while(head) {
        NODE* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {

    int v[] = {1, 2, 2, 1};
    int size = sizeof(v) / sizeof(v[0]);

    NODE* head = array2list(v, size);
    
    printList(head);

    if(isPalindrome(head)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    freelist(head);

    return 0;
}