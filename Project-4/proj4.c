#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LENGTH 80;
/* Adit Syed 
Data Structures CSCI-230
Project 4
3/24/2025 (current date)
Project 5. This file has both the main and the code for designing the Doubly Linked List. 
Node here refers to the newly made structure and not the default node. 
The code represents a basic linked list that can go forwards & backwards. 
*/
typedef struct node
{
    int key;
    struct node *nextPtr;
    struct node *prevPtr;
    
    
}node;
typedef struct list
{
  node *headPtr;
  node *tailPtr;
} list;


void printNode(node *theNode)
{
    printf("theNode-> key: %d\n", theNode->key);
    

}
int addList(list *theList, int key){

    // Memory allocation for the node to the pointer 
    node *newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
      return -1;
    }

    newNode-> key = key;
    newNode->nextPtr = NULL;
    newNode->prevPtr = NULL; 

    if (theList->headPtr == NULL) {
        theList->headPtr = newNode;
        theList->tailPtr = newNode;
    }else{
        theList->tailPtr->nextPtr = newNode;
        newNode->prevPtr = theList->tailPtr;
        theList->tailPtr = newNode; 
    }

    return 0;
};

void printList(list *theList){
    if (theList == NULL || theList->headPtr == NULL) {
        printf("List is empty.\n");
    }
    node *current = theList->headPtr;
    while (current != NULL) {
        printf("%d", current->key);
        current = current->nextPtr;
    }
    printf("\n");
    
};

void printListBack(list *theList){
    if (theList == NULL || theList->headPtr == NULL) {
        printf("List is empty.\n");
    }
    node *current = theList->tailPtr;
    
    while (current != NULL){
        printf("%d", current->key);
        current = current->prevPtr;
    }
    printf("\n");
   
};

void delList(list *theList){
    if (theList == NULL || theList->headPtr == NULL) {
        return ;
    }
    
    node *current = theList->headPtr;
    node *next; 
    while (current != NULL) {
        next = current->nextPtr;
        free(current);
        current = next;
    }

    theList->headPtr = NULL;
    theList->tailPtr = NULL;
};

int main (void){

    char inputString[80];
    int i;
    list myList;
    myList.headPtr = NULL;
    myList.tailPtr = NULL;

    printf("Give me a long integer: ");
    fgets(inputString, 80, stdin);


    if (strlen(inputString) > 0 && inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }
    
    
    for (i = 0; i < strlen(inputString); i++)
    {
        addList(&myList, inputString[i] - '0');
    }


    

    printf("Forwards: ");
    printList(&myList);

    printf("Backwards: ");
    printListBack(&myList);


    delList(&myList); // free memory


    return 0;

};

