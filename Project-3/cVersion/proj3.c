#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Adit Syed Afnan
 * Project 3: Linked List for Large Integer Representation
 * CSCI-230 | Date: 2025-03-04
 *
 * This program reads a really large integer from user input,
 * stores each digit in a linked list, and then prints it.
 * It mimics a Java-style class design using structs and functions.
 */

/**
 * @struct Node
 * Represents a single node in the linked list.
 */
typedef struct Node {
    int key;                // Stores a single digit
    struct Node* next;      // Pointer to the next node
} Node;

/**
 * @struct List
 * Represents the linked list, which stores digits of a large integer.
 */
typedef struct List {
    Node* head;             // Pointer to the head (first node) of the list
} List;

// --- Node Functions ---

/**
 * @brief Creates a new node with a given digit.
 * 
 * @param item The digit to store.
 * @return Pointer to the newly created node.
 */
Node* createNode(int item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->key = item;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Prints the digit stored in the node.
 * 
 * @param node Pointer to the node to print.
 */
void printNode(Node* node) {
    printf("%d ", node->key);
}

// --- List Functions ---

/**
 * @brief Initializes a new empty list.
 * 
 * @return An empty list with head set to NULL.
 */
List createList() {
    List list;
    list.head = NULL;
    return list;
}

/**
 * @brief Adds a digit to the end of the list.
 * 
 * @param list Pointer to the List.
 * @param item Digit to add.
 * @return Pointer to the new node added.
 */
Node* addToList(List* list, int item) {
    Node* newNode = createNode(item);

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    return newNode;
}

/**
 * @brief Prints all digits in the list.
 * 
 * @param list Pointer to the list.
 */
void printList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printNode(current);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief Frees all memory used by the list.
 * 
 * @param list Pointer to the list.
 */
void freeList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    list->head = NULL;
}

// --- Main Function ---

int main() {
    char inputline[1024];
    List theList = createList();

    printf("Enter a really large integer: ");
    fgets(inputline, sizeof(inputline), stdin);
    inputline[strcspn(inputline, "\n")] = '\0'; // remove trailing newline

    for (int i = 0; inputline[i] != '\0'; i++) {
        if (inputline[i] >= '0' && inputline[i] <= '9') {
            int digit = inputline[i] - '0';
            addToList(&theList, digit);
        }
    }

    printf("Here is your really large integer: ");
    printList(&theList);

    freeList(&theList);

    return 0;
}
