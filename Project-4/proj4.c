#include <stdio.h>   // Required for standard input/output functions like printf, fgets
#include <stdlib.h>  // Required for memory allocation functions like malloc, free
#include <string.h>  // Required for string manipulation functions like strlen

// The following macro definition is commented out because it has a semicolon at the end,
// which can lead to unexpected behavior when used in some contexts (e.g., if statements without braces).
// It's good practice to avoid semicolons at the end of #define macros unless specifically intended.
// #define STR_LENGTH 80;

/*
 * Adit Syed
 * Data Structures CSCI-230
 * Project 4: Doubly Linked List Implementation
 * Date: 2025-03-24
 *
 * This file contains the implementation of a basic Doubly Linked List
 * and the main function to demonstrate its functionality.
 *
 * A Doubly Linked List allows traversal in both forward and backward directions,
 * unlike a Singly Linked List which only allows forward traversal.
 * Each node in this list maintains pointers to both the next and the previous node.
 */

// --- Structure Definitions ---

/**
 * @brief Defines the structure for a node in the Doubly Linked List.
 * Each node holds an integer key and pointers to the next and previous nodes in the list.
 */
typedef struct node {
    int key;             // The integer data stored in this node.
    struct node *nextPtr;  // Pointer to the next node in the list. NULL if this is the tail.
    struct node *prevPtr;  // Pointer to the previous node in the list. NULL if this is the head.
} node;

/**
 * @brief Defines the structure for the Doubly Linked List itself.
 * It contains pointers to the head (first node) and the tail (last node) of the list.
 */
typedef struct list {
    node *headPtr; // Pointer to the first node in the list.
    node *tailPtr; // Pointer to the last node in the list.
} list;


// --- Function Prototypes (Optional but good practice for larger files) ---
// void printNode(node *theNode);
// int addList(list *theList, int key);
// void printList(list *theList);
// void printListBack(list *theList);
// void delList(list *theList);


// --- Function Implementations ---

/**
 * @brief Prints the key of a single node.
 * This function is simple and primarily used for debugging or specific node inspection.
 *
 * @param theNode A pointer to the node whose key is to be printed.
 */
void printNode(node *theNode) {
    printf("theNode-> key: %d\n", theNode->key);
}

/**
 * @brief Adds a new node with the given key to the end of the Doubly Linked List.
 * Handles both empty and non-empty list scenarios.
 *
 * @param theList A pointer to the list structure to which the node will be added.
 * @param key The integer value to be stored in the new node.
 * @return 0 on successful addition, -1 if memory allocation fails.
 */
int addList(list *theList, int key) {
    // Dynamically allocate memory for a new node.
    node *newNode = (node *)malloc(sizeof(node));
    // Check if memory allocation was successful.
    if (newNode == NULL) {
        // Return -1 to indicate a memory allocation error.
        return -1;
    }

    // Initialize the new node's members.
    newNode->key = key;         // Set the data key for the new node.
    newNode->nextPtr = NULL;    // New node is added to the end, so its next pointer is NULL.
    newNode->prevPtr = NULL;    // Will be set below if the list is not empty.

    // Check if the list is currently empty.
    if (theList->headPtr == NULL) {
        // If the list is empty, the new node becomes both the head and the tail.
        theList->headPtr = newNode;
        theList->tailPtr = newNode;
    } else {
        // If the list is not empty, append the new node to the end.
        // The current tail's next pointer points to the new node.
        theList->tailPtr->nextPtr = newNode;
        // The new node's previous pointer points back to the old tail.
        newNode->prevPtr = theList->tailPtr;
        // Update the list's tail pointer to the newly added node.
        theList->tailPtr = newNode;
    }

    // Return 0 to indicate successful addition.
    return 0;
}

/**
 * @brief Prints all keys in the Doubly Linked List from head to tail (forwards).
 *
 * @param theList A pointer to the list structure to be printed.
 */
void printList(list *theList) {
    // Check if the list itself is invalid or empty.
    if (theList == NULL || theList->headPtr == NULL) {
        printf("List is empty.\n");
        return; // Exit the function if the list is empty.
    }

    // Start traversal from the head of the list.
    node *current = theList->headPtr;
    // Iterate through the list until the end is reached (current becomes NULL).
    while (current != NULL) {
        printf("%d", current->key); // Print the key of the current node.
        current = current->nextPtr; // Move to the next node.
    }
    printf("\n"); // Print a newline character after printing all elements for clean output.
}

/**
 * @brief Prints all keys in the Doubly Linked List from tail to head (backwards).
 *
 * @param theList A pointer to the list structure to be printed.
 */
void printListBack(list *theList) {
    // Check if the list itself is invalid or empty.
    if (theList == NULL || theList->headPtr == NULL) { // headPtr check implies list is empty
        printf("List is empty.\n");