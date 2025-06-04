/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 8: Queue Data Structure Header File
 * Date: 2025-05-06
 *
 * This header file defines the structures and function prototypes for a
 * basic Queue data structure implemented using a linked list.
 * It provides the necessary declarations to manage a First-In, First-Out (FIFO) collection of integers.
 */

#ifndef QUEUE_H // Include guard to prevent multiple inclusions of this header file
#define QUEUE_H // Define a unique macro to mark this header as included

/**
 * @struct QueueNode
 * @brief Represents a single node within the queue.
 *
 * Each node stores an integer value (typically a vertex ID in graph problems)
 * and a pointer to the next node in the queue, forming a linked list.
 */
typedef struct QueueNode
{
	int vertex;           /**< The integer value (e.g., vertex ID) stored in this queue node. */
	struct QueueNode* next;   /**< Pointer to the next node in the queue. NULL if this is the last node. */
} QueueNode; // 'QueueNode' is an alias for 'struct QueueNode'

/**
 * @struct Queue
 * @brief Represents the Queue data structure itself.
 *
 * This structure holds pointers to the 'front' (first element to be dequeued)
 * and 'rear' (last element to be enqueued) of the queue.
 * These pointers enable efficient enqueue and dequeue operations (O(1) time complexity).
 */
typedef struct
{
	QueueNode* front; /**< Pointer to the front (head) of the queue. NULL if the queue is empty. */
	QueueNode* rear;  /**< Pointer to the rear (tail) of the queue. NULL if the queue is empty. */
} Queue; // 'Queue' is an alias for the anonymous struct defining the queue.

/**
 * @brief Creates and initializes a new, empty Queue.
 *
 * This function allocates memory for a new Queue structure and sets its
 * front and rear pointers to NULL, indicating an empty queue.
 *
 * @return A pointer to the newly created Queue, or NULL if memory allocation fails.
 */
Queue* createQueue(void);

/**
 * @brief Checks if the given queue is empty.
 *
 * An empty queue is identified by its 'front' pointer being NULL.
 *
 * @param queue A pointer to the Queue to be checked.
 * @return 1 (true) if the queue is empty, 0 (false) otherwise.
 */
int isQueueEmpty(Queue* queue);

/**
 * @brief Adds a new integer vertex to the rear of the queue (enqueue operation).
 *
 * A new QueueNode is created for the given vertex. If the queue is empty,
 * this new node becomes both the front and rear. Otherwise, it's linked
 * after the current rear node.
 *
 * @param queue A pointer to the Queue to which the vertex will be added.
 * @param vertex The integer value (e.g., vertex ID) to be enqueued.
 */
void enqueue(Queue* queue, int vertex);

/**
 * @brief Removes and returns the integer vertex from the front of the queue (dequeue operation).
 *
 * This function retrieves the vertex from the node at the front of the queue,
 * then removes and frees that node. The queue's 'front' pointer is updated.
 * It's crucial to check if the queue is empty before calling this function.
 *
 * @param queue A pointer to the Queue from which the vertex will be removed.
 * @return The integer value of the vertex that was at the front of the queue.
 * (Note: Behavior is undefined or an error might occur if dequeued from an empty queue).
 */
int dequeue(Queue* queue);

/**
 * @brief Frees all memory associated with the queue.
 *
 * This function deallocates all QueueNode elements in the queue, then
 * deallocates the Queue structure itself. It effectively empties and destroys the queue.
 *
 * @param queue A pointer to the Queue to be freed.
 */
void freeQueue(Queue* queue);

#endif // QUEUE_H
