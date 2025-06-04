/* Adit Syed 
Data Structures CSCI-230
Project 4
3/24/2025 (current date)
Project 5. This is the header file. Contain the name of the functions and the defined structures. Excludes the main.
*/


typedef struct node {
    int key;
    struct node *nextPtr;
    struct node *prevPtr;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

int addList(list *theList, int key);
void printList(list *theList);
void printListBack(list *theList);
void delList(list *theList);
