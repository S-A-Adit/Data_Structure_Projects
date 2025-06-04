#include <stdio.h>   // Required for standard input/output functions like printf
#include <stdlib.h>  // Required for memory management functions like malloc and exit

/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 9: Queue Implementation
 * Date: 2025-05-06
 *
 * This file contains the complete implementation of a Queue data structure
 * using a linked list. It provides functions for:
 * - Creating a new, empty queue.
 * - Checking if a queue is empty.
 * - Adding elements (enqueue) to the rear of the queue.
 * - Removing elements (dequeue) from the front of the queue.
 * - Freeing all dynamically allocated memory associated with the queue.
 */

/**
 * @struct QueueNode
 * @brief Represents a single node within the queue.
 *
 * Each node stores an integer 'vertex' (likely representing a graph vertex or data item)
 * and a pointer 'next' to the subsequent node in the queue, forming a singly linked list.
 */
typedef struct QueueNode
{
	int vertex;           /**< The integer data value stored in this node. */
	struct QueueNode* next; /**< Pointer to the next node in the queue. NULL if this is the last node. */
} QueueNode;

/**
 * @struct Queue
 * @brief Represents the queue data structure itself.
 *
 * This structure holds pointers to the 'front' (first node) and 'rear' (last node)
 * of the queue. These pointers allow for efficient enqueue (add to rear) and
 * dequeue (remove from front) operations.
 */
typedef struct
{
	QueueNode* front; /**< Pointer to the front (first) node of the queue. NULL if the queue is empty. */
	QueueNode* rear;  /**< Pointer to the rear (last) node of the queue. NULL if the queue is empty. */
} Queue;

/**
 * @brief Creates and initializes a new, empty Queue.
 *
 * This function dynamically allocates memory for a Queue structure and
 * sets its front and rear pointers to NULL, signifying an empty queue.
 * It includes error handling for memory allocation failure.
 *
 * @return A pointer to the newly created Queue, or exits the program if malloc fails.
 */
Queue* createQueue(void){
    // Allocate memory for the Queue structure.
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));

    // Check if memory allocation was successful.
    if (newQueue == NULL) {
        printf("Malloc Failed\n"); // Print error message if allocation fails.
        exit(0);                   // Exit the program.
    }
    // Initialize the front and rear pointers to NULL, indicating an empty queue.
    newQueue->front = NULL;
    newQueue->rear = NULL;

    return newQueue; // Return the pointer to the newly created queue.
}

/**
 * @brief Checks if the given Queue is empty.
 *
 * A queue is considered empty if its front pointer is NULL.
 *
 * @param queue A pointer to the Queue to be checked.
 * @return 1 (true) if the queue is empty, 0 (false) otherwise.
 */
int isQueueEmpty(Queue* queue){
    // Returns 1 if the front pointer is NULL (queue is empty), otherwise returns 0.
    return (queue->front == NULL);
}

/**
 * @brief Adds a new integer vertex to the rear of the Queue (enqueue operation).
 *
 * This function dynamically allocates a new QueueNode, sets its vertex value,
 * and links it to the end of the queue. If the queue is empty, the new node
 * becomes both the front and the rear.
 * It includes error handling for memory allocation failure.
 *
 * @param queue A pointer to the Queue to which the vertex will be added.
 * @param vertex The integer value to be added to the queue.
 */
void enqueue(Queue* queue, int vertex){
    // Allocate memory for a new QueueNode.
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    // Check if memory allocation was successful.
    if (newNode == NULL) {
        printf("Malloc Failed\n"); // Print error message if allocation fails.
        exit(0);                   // Exit the program.
    }

    // Set the vertex value for the new node.
    newNode->vertex = vertex;
    // The new node will be the last, so its 'next' pointer is NULL.
    newNode->next = NULL;

    // Check if the queue is currently empty.
    if (queue->rear == NULL) {
        // If empty, the new node becomes both the front and the rear of the queue.
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // If not empty, link the current rear node's 'next' pointer to the new node.
        queue->rear->next = newNode;
        // Update the 'rear' pointer of the queue to point to the new node.
        queue->rear = newNode;
    }
}

/**
 * @brief Removes and returns the integer vertex from the front of the Queue (dequeue operation).
 *
 * This function retrieves the vertex from the front node, updates the front pointer
 * to the next node, and frees the memory of the removed node.
 * It includes error handling if an attempt is made to dequeue from an empty queue.
 *
 * @param queue A pointer to the Queue from which the vertex will be removed.
 * @return The integer vertex value that was at the front of the queue.
 */
int dequeue(Queue* queue){
   // Check if the queue is empty before attempting to dequeue.
   if(queue->front == NULL){
    printf("DEQUE found the Queue to be empty!"); // Print error message.
    exit(0);                                      // Exit the program.
   }

   // Store a temporary pointer to the front node.
   QueueNode* tempNode = queue->front;
   // Get the vertex value from the front node to return it.
   int temp = tempNode->vertex;
   // Move the 'front' pointer to the next node in the queue.
   queue->front = queue->front->next;

   // If the front becomes NULL after dequeuing, it means the queue is now empty.
   // In this case, the rear pointer must also be set to NULL.
   if (queue->front == NULL){
       queue->rear = NULL;
   }

   // Free the memory of the node that was just removed.
   free(tempNode);
   // Return the vertex value that was dequeued.
   return temp;
}

/**
 * @brief Frees all dynamically allocated memory associated with the Queue.
 *
 * This function iterates through all nodes in the queue, freeing each one,
 * and then frees the Queue structure itself. It's crucial to call this
 * function to prevent memory leaks when the queue is no longer needed.
 *
 * @param queue A pointer to the Queue to be freed.
 */
void freeQueue(Queue* queue){
    // Start from the front of the queue.
    QueueNode* tempPtr = queue->front;

    // Traverse the queue, freeing each node one by one.
    while (tempPtr != NULL) {
        // Move the 'front' pointer to the next node *before* freeing the current 'tempPtr'.
        // This ensures we don't lose the reference to the rest of the queue.
        queue->front = queue->front->next;
        free(tempPtr);      // Free the memory of the current node.
        tempPtr = queue->front; // Update tempPtr to the new front (or NULL if list is exhausted).
    }

    // After all nodes are freed, free the Queue structure itself.
    free(queue);
}