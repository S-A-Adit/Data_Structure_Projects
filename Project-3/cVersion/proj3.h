#ifndef PROJECT4_H
#define PROJECT4_H

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

Node* createNode(int item);
void printNode(Node* node);
List createList();
Node* addToList(List* list, int item);
void printList(List* list);
void freeList(List* list);

#endif
