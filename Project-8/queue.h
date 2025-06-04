/* Adit Syed Afnan
Data Structures CSCI-230
Project 9
5/6/2025 
This is the header file for queue.
*/
typedef struct QueueNode
{
	int vertex;
	struct QueueNode* next;
} QueueNode;

typedef struct
{
	QueueNode* front;
	QueueNode* rear;
} Queue;

Queue* createQueue(void);
int isQueueEmpty(Queue* queue);   
void enqueue(Queue* queue, int vertex);
int dequeue(Queue* queue);
void freeQueue(Queue* queue);
