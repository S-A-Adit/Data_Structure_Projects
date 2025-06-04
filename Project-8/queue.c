#include <stdio.h>
#include <stdlib.h>

/* Adit Syed Afnan
Data Structures CSCI-230
Project 9
5/6/2025 
This is the queue file that doe the creation adding and deletion and freeing of the queue.
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


Queue* createQueue(void){
 Queue* newQueue = (Queue*)malloc(sizeof(Queue));

 if (newQueue == NULL)
 {  printf("Malloc Failed\n");
    exit(0);
 }
 newQueue->front = NULL;
 newQueue->rear = NULL;
 
 return newQueue;
  

}
int isQueueEmpty(Queue* queue){
    return (queue->front == NULL);
    
}

void enqueue(Queue* queue, int vertex){
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL)
    {
        printf("Malloc Failed\n");
        exit(0);
    }
    
    newNode->vertex = vertex;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        
        queue->front = newNode;
        queue->rear = newNode;
    } else {
       
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

}

int dequeue(Queue* queue){
      
   if(queue->front == NULL){
    printf("DEQUE found the Queue to be empty!");
    exit(0);
   }

   QueueNode* tempNode = queue->front;
   int temp = tempNode->vertex;
   queue->front = queue->front->next;

   if (queue->front == NULL){
       queue->rear = NULL;
   }

   free(tempNode);
   return temp;
}

void freeQueue(Queue* queue){
    QueueNode* tempPtr = queue->front;

    while (tempPtr != NULL)
    {   
        
        queue->front = queue->front->next;
        free(tempPtr);
        tempPtr = queue->front;
    }
    
     free(queue);
}



