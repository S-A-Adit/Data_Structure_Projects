/* Adit Syed
 * Data Structures CSCI-230
 * Project 4
 * Date: 2025-03-24
 *
 * Project 5: Doubly Linked List Header File
 * This header file declares the fundamental data structures (nodes and lists)
 * and function prototypes for implementing a doubly linked list.
 * It serves as the interface for interacting with the doubly linked list functionality.
 */

#ifndef DOUBLY_LINKED_LIST_H // Include guard to prevent multiple inclusions of this header file
#define DOUBLY_LINKED_LIST_H // Defines a unique macro to indicate that this header has been included

/**
 * @struct node
 * @brief Represents a single element or node within the doubly linked list.
 *
 * Each node stores an integer value and contains pointers that link it to
 * the subsequent node (nextPtr) and the preceding node (prevPtr) in the list.
 * This structure enables bidirectional traversal.
 */
typedef struct node {
    int key;          /**< The integer data value held by this node. */
    struct node *nextPtr; /**< Pointer to the next node in the sequence. NULL if this is the last node. */
    struct node *prevPtr; /**< Pointer to the previous node in the sequence. NULL if this is the first node. */
} node; // 'node' is an alias for 'struct node'

/**
 * @struct list
 * @brief Represents the overall doubly linked list data structure.
 *
 * This structure maintains pointers to the first node (head) and the last node (tail)
 * of the list. These pointers provide direct access to both ends, facilitating
 * efficient insertion and deletion operations at the extremities.
 */
typedef struct list {
    node *head; /**< Pointer to the first node of the list. If the list is empty, this will be NULL. */
    node *tail; /**< Pointer to the last node of the list. If the list is empty, this will be NULL. */
} list; // 'list' is an alias for 'struct list'

/**
 * @brief Adds a new node with the specified integer key to the end of the doubly linked list.
 *
 * This function allocates memory for a new node, assigns the provided 'key' to it,
 * and then links it to the current tail of 'theList'. If the list is initially empty,
 * the new node becomes both the head and the tail.
 *
 * @param theList A pointer to the 'list' structure to which the new node will be appended.
 * @param key The integer value to be stored in the new node.
 * @return Returns 0 upon successful addition, or a non-zero value if memory allocation fails.
 */
int addList(list *theList, int key);

/**
 * @brief Prints the integer keys of all nodes in the list from head to tail.
 *
 * This function traverses the doubly linked list starting from the 'head' node
 * and prints the 'key' of each node in sequential order to the standard output.
 * Each key is typically followed by a space, and a newline character is printed
 * after all elements have been displayed.
 *
 * @param theList A pointer to the 'list' structure whose elements are to be printed.
 */
void printList(list *theList);

/**
 * @brief Prints the integer keys of all nodes in the list from tail to head (in reverse order).
 *
 * This function traverses the doubly linked list backward, starting from the 'tail' node
 * and prints the 'key' of each node in reverse sequential order to the standard output.
 * Each key is typically followed by a space, and a newline character is printed
 * after all elements have been displayed.
 *
 * @param theList A pointer to the 'list' structure whose elements are to be printed in reverse.
 */
void printListBack(list *theList);

/**
 * @brief Deletes a node from the doubly linked list.
 *
 * This function is intended to remove a node from 'theList'.
 * (Note: The current function signature `void delList(list *theList);`
 * suggests it might remove a fixed node (e.g., the head or tail), or
 * it might be intended to be extended to take a key or position for deletion.)
 *
 * @param theList A pointer to the 'list' structure from which a node will be deleted.
 */
void delList(list *theList);

#endif // DOUBLY_LINKED_LIST_H