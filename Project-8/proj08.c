#include <stdio.h>   // For standard input/output functions like printf, fgets, sscanf
#include <stdlib.h>  // For general utilities like malloc, free, exit
#include <string.h>  // For string manipulation functions like strlen
#include "queue.h"   // Include the custom Queue header file (from Project 9)

/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 8: Graph Breadth-First Search (BFS) Implementation
 * Date: 2025-05-06
 *
 * This program demonstrates graph creation and traversal using Breadth-First Search (BFS).
 * It allows the user to input graph edges, builds an adjacency list representation of the graph,
 * sorts the adjacency lists for consistent output, performs a BFS traversal starting from vertex 'A',
 * and finally frees all dynamically allocated memory.
 */

/**
 * @struct Node
 * @brief Represents a node (or edge) in the adjacency list.
 *
 * Each Node in an adjacency list points to a neighbor vertex in the graph.
 * It stores the 'vertex' index of the neighbor and a 'next' pointer
 * to the next neighbor in the list for the current source vertex.
 */
typedef struct Node
{
	int vertex;         /**< The index of the neighboring vertex. */
	struct Node* next;  /**< Pointer to the next Node in the adjacency list (another neighbor). */
} Node;

// Define the maximum number of vertices the graph can have.
// Vertices are assumed to be represented by indices 0 to MAX_VERTICES-1.
#define MAX_VERTICES 10

/**
 * @brief Adds an undirected edge between two vertices in the adjacency list representation.
 *
 * This function creates a new node for the 'toIndex' vertex and adds it to the
 * adjacency list of 'fromIndex'. Since it's an undirected graph, it's called
 * twice to add edges in both directions (from -> to, and to -> from).
 *
 * @param adjacencyList An array of Node pointers, where each index represents a vertex
 * and points to the head of its adjacency list.
 * @param fromIndex The integer index of the source vertex.
 * @param toIndex The integer index of the destination vertex.
 */
void addEdge(Node* adjacencyList[], int fromIndex, int toIndex){
  // Allocate memory for a new Node to represent the 'toIndex' neighbor.
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Malloc failed in add Edge!\n"); // Error message if memory allocation fails.
    exit(0);                               // Exit the program.
  }
    // Set the vertex field of the new node to the destination index.
    newNode->vertex = toIndex;
    // Link the new node to the current head of the adjacency list for 'fromIndex'.
    // This effectively adds the new node at the beginning of the list (prepending).
    newNode->next = adjacencyList[fromIndex];

    // Update the head of the adjacency list for 'fromIndex' to point to the new node.
    adjacencyList[fromIndex] = newNode;
}

/**
 * @brief Sorts the adjacency lists for each vertex in ascending order of neighbor vertex indices.
 *
 * This function iterates through each vertex's adjacency list and sorts its nodes
 * based on their 'vertex' values. This ensures a consistent order for traversal
 * algorithms like BFS or DFS, especially for testing or predictable output.
 * It uses an insertion sort-like approach for each individual linked list.
 *
 * @param adjacencyList An array of Node pointers representing the graph's adjacency lists.
 */
void sortAdjacencyLists(Node* adjacencyList[])
{
  // Iterate through each vertex in the graph.
  for (int index = 0; index < MAX_VERTICES; index++)
  {
    Node* sorted = NULL;          // 'sorted' will be the head of the new, sorted list for the current index.
    Node* current = adjacencyList[index]; // 'current' points to the head of the original (unsorted) list.

    // Traverse the original adjacency list.
    while (current != NULL)
    {
  	  Node* nextNode = current->next; // Store the next node before 'current' is potentially re-linked.
  	  Node** insertPosition = &sorted; // Start at the head of the 'sorted' list (or where it will be).

       // Find the correct position to insert 'current' into the 'sorted' list.
       // It continues as long as 'insertPosition' is not NULL and the node at 'insertPosition'
       // has a 'vertex' value less than 'current->vertex'.
       while (*insertPosition != NULL &&
             (*insertPosition)->vertex < current->vertex)
       {
    	    // Move 'insertPosition' to point to the 'next' pointer of the current node in 'sorted'.
    	    insertPosition = &(*insertPosition)->next;
       }

       // Insert 'current' node into the 'sorted' list at the found position.
       // 'current->next' points to the node that was originally at '*insertPosition'.
       current->next = *insertPosition;
       // '*insertPosition' now points to 'current', effectively inserting it.
       *insertPosition = current;
       // Move to the next node in the original (unsorted) list.
       current = nextNode;
    }

    // Update the adjacency list for the current index to point to the newly sorted list.
    adjacencyList[index] = sorted;
  }
}

/**
 * @brief Performs a Breadth-First Search (BFS) traversal starting from a given vertex.
 *
 * BFS explores all the neighbor nodes at the current depth level before moving
 * on to the nodes at the next depth level. It uses a queue to manage the order
 * of vertices to visit and an array to keep track of visited vertices to prevent cycles.
 *
 * @param adjacencyList An array of Node pointers representing the graph's adjacency lists.
 * @param startIndex The integer index of the vertex from which to start the BFS traversal.
 */
void bfs(Node* adjacencyList[], int startIndex){
 // 'visited' array to keep track of visited vertices. Initialized to all zeros (unvisited).
 int visited [MAX_VERTICES] = {0};

 // Create a new Queue instance for BFS traversal.
 Queue* queue = createQueue();

 // Mark the starting vertex as visited.
 visited[startIndex] = 1;

 // Enqueue the starting vertex to begin the traversal.
 enqueue(queue, startIndex);

 // Continue BFS as long as the queue is not empty.
 while (!isQueueEmpty(queue))
 {
  // Dequeue a vertex from the front of the queue to process it.
  int currentvertex = dequeue(queue);
  // Print the character representation of the current vertex (e.g., 0+'A' = 'A').
  printf("%c ", currentvertex + 'A');

  // Get the adjacency list for the current vertex.
  Node* currentNode = adjacencyList[currentvertex];

  // Traverse all neighbors of the current vertex.
  while (currentNode != NULL)
  {
    int neighbour = currentNode->vertex; // Get the index of the neighbor.
    // If the neighbor has not been visited yet:
    if(!visited[neighbour]){
      visited[neighbour] = 1;     // Mark the neighbor as visited.
      enqueue(queue, neighbour);  // Enqueue the neighbor for future processing.
    }
    // Move to the next neighbor in the adjacency list.
    currentNode = currentNode->next;
  }
 }

 // Free all memory associated with the queue after BFS is complete.
 freeQueue(queue);

 printf("\n"); // Print a newline character for formatting after BFS output.
}


/**
 * @brief Frees all dynamically allocated memory used by the graph's adjacency lists.
 *
 * This function iterates through each adjacency list and deallocates all the
 * Node structures (which represent edges) within them. It's crucial for
 * preventing memory leaks when the graph is no longer needed.
 *
 * @param adjacencyList An array of Node pointers representing the graph's adjacency lists.
 */
void freeGraph(Node* adjacencyList[]) {
   // Iterate through each vertex's adjacency list.
   for (int i = 0; i < MAX_VERTICES; i++){
    Node *current = adjacencyList[i]; // Start from the head of the current list.

    // Traverse the linked list and free each node.
    while (current != NULL)
    {
      Node *temp = current; // Store a temporary pointer to the current node.
      current = current->next; // Move 'current' to the next node before freeing 'temp'.
      free(temp);            // Free the memory of the current node.
    }
    adjacencyList[i] = NULL; // Set the head of the list to NULL after all nodes are freed.
   }
}

/**
 * @brief Main function of the graph program.
 *
 * This function initializes the graph, prompts the user to input edges,
 * performs necessary graph operations (sorting, BFS), and cleans up memory.
 * Edges are input as characters (e.g., 'A B' for an edge between A and B).
 */
int main(){
  // Declare the adjacency list array. Initialize all pointers to NULL (empty lists).
  Node* adjacencyList[MAX_VERTICES] = {NULL};

  // Buffers for user input.
  char inputString[80]; // To read the entire line of input.
  char charOne, charTwo; // To store the two character vertices from input.

  // Loop indefinitely until the user enters '0 0' to exit.
  while (1)
  {
    printf("Input format: A B or 0 0 to exit: "); // Prompt for edge input.
    fgets(inputString, 80, stdin);               // Read the entire line of input.
    inputString[strlen(inputString)-1] = '\0';   // Remove the newline character from the input string.
    // Parse the two character vertices from the input string.
    sscanf(inputString, " %c %c", &charOne, &charTwo);

    // Check for the exit condition.
    if (charOne == '0' && charTwo == '0')
    {
      break; // Exit the loop.
    }

    // Convert character vertices (e.g., 'A', 'B') to integer indices (0, 1)
    // by subtracting the ASCII value of 'A'.
    int fromIndex = charOne - 'A';
    int toIndex = charTwo - 'A';

    // Add the edge in both directions since this is an undirected graph.
    addEdge(adjacencyList, fromIndex, toIndex); // Add edge from charOne to charTwo.
    addEdge(adjacencyList, toIndex, fromIndex); // Add edge from charTwo to charOne.
  }

  // Sort the adjacency lists to ensure consistent output for BFS.
  sortAdjacencyLists(adjacencyList);

  // Perform Breadth-First Search starting from vertex 'A' (index 0).
  printf("BFS Visit: ");
  bfs(adjacencyList, 0);

  // Free all dynamically allocated memory used by the graph.
  freeGraph(adjacencyList);

  return 0; // Indicate successful program execution.
}