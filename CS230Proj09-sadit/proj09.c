#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/* Adit Syed Afnan
Data Structures CSCI-230
Project 9
5/6/2025 
This is the main file where the node is used and edges and vertex is added.
*/

typedef struct Node
{
	int vertex;
	struct Node* next;
} Node;

#define MAX_VERTICES 10


void addEdge(Node* adjacencyList[], int fromIndex, int toIndex){
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Malloc failed in add Edge!\n");
    exit(0);
  }
    newNode->vertex = toIndex;
    newNode->next = adjacencyList[fromIndex];

    adjacencyList[fromIndex] = newNode;
}

void sortAdjacencyLists(Node* adjacencyList[])
{
  for (int index = 0; index < MAX_VERTICES; index++)
  {
    Node* sorted = NULL;
    Node* current = adjacencyList[index];


    while (current != NULL)
    {
  	  Node* nextNode = current->next;
  	  Node** insertPosition = &sorted;

       while (*insertPosition != NULL &&
             (*insertPosition)->vertex < current->vertex)
       {
    	    insertPosition = &(*insertPosition)->next;
       }

       current->next = *insertPosition;
       *insertPosition = current;
       current = nextNode;
    }

    adjacencyList[index] = sorted;
  }
}

void bfs(Node* adjacencyList[], int startIndex){
 int visited [MAX_VERTICES] = {0};

 Queue* queue = createQueue();

 visited[startIndex] = 1;

 enqueue(queue, startIndex);

 while (!isQueueEmpty(queue))
 {
  int currentvertex = dequeue(queue);
  printf("%c ", currentvertex + 'A');



  Node* currentNode = adjacencyList[currentvertex];

  while (currentNode != NULL)
  {
    int neighbour = currentNode->vertex;
    if(!visited[neighbour]){
      visited[neighbour] = 1;
      enqueue(queue, neighbour);
    }

    currentNode = currentNode->next;
  }
  
 }

 freeQueue(queue);

 printf("\n");
 
}


void freeGraph(Node* adjacencyList[]) {
   for (int i =0; i< MAX_VERTICES; i++){
    Node *current = adjacencyList [i];

    while (current != NULL)
    {
      Node *temp = current;
      current = current->next;
      free(temp);

    }
    adjacencyList[i] = NULL;


   }
   
}

int main(){
  Node* adjacencyList[MAX_VERTICES] = {NULL};
  
  char inputString[80];
  char charOne, charTwo;

  while (1)
  {
    printf("Input format: A B or 0 0 to exit:");
    fgets(inputString, 80, stdin);
    inputString[strlen(inputString)-1] = '\0';
    sscanf(inputString, " %c %c", &charOne, &charTwo);
    
    if (charOne == '0' && charTwo == '0')
    {
      break;
    }
    
    int fromIndex = charOne - 'A';
    int toIndex = charTwo - 'A';
    addEdge(adjacencyList, fromIndex, toIndex);
    addEdge(adjacencyList, toIndex, fromIndex);  

  }
  sortAdjacencyLists(adjacencyList);
  printf("BFS Visit: ");
  bfs(adjacencyList, 0);
  freeGraph(adjacencyList);
  return 0;
}
   




    

  

