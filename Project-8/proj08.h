/* Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 9: Graph Traversal (BFS) and Adjacency List Utilities
 * Date: 2025-05-06
 *
 * This header file declares the structures and function prototypes
 * necessary for representing a graph using adjacency lists and performing
 * a Breadth-First Search (BFS) traversal, along with utility functions
 * for graph manipulation and memory management.
 */

#ifndef GRAPH_ALGORITHMS_H // Include guard to prevent multiple inclusions of this header file
#define GRAPH_ALGORITHMS_H // Define a unique macro to mark this header as included

/**
 * @struct Node
 * @brief Represents a node in an adjacency list.
 *
 * In the context of an adjacency list, this 'Node' typically represents
 * a vertex that is adjacent to another vertex. It contains the 'vertex' ID
 * and a pointer 'next' to the subsequent adjacent vertex in the list.
 */
typedef struct Node
{
    int vertex;       /**< The integer ID of the adjacent vertex. */
    struct Node* next; /**< Pointer to the next Node in the adjacency list. NULL if this is the last adjacent vertex. */
} Node;

/**
 * @brief Adds an edge to the graph represented by adjacency lists.
 *
 * This function creates a directed edge from 'fromIndex' to 'toIndex'.
 * It adds 'toIndex' to the adjacency list of 'fromIndex'.
 * (Note: For an undirected graph, you would typically call this function twice:
 * once for fromIndex -> toIndex, and once for toIndex -> fromIndex).
 *
 * @param adjacencyList[] An array of Node pointers, where each index represents a vertex
 * and the pointer at that index points to the head of its adjacency list.
 * @param fromIndex The integer ID of the starting vertex of the edge.
 * @param toIndex The integer ID of the ending (adjacent) vertex of the edge.
 */
void addEdge(Node* adjacencyList[], int fromIndex, int toIndex);

/**
 * @brief Sorts the adjacency lists of the graph.
 *
 * This function is intended to sort the linked lists associated with each vertex
 * in the 'adjacencyList' array. Sorting can be useful for standardized output
 * or for certain graph algorithms that benefit from ordered adjacency lists.
 * The specific sorting algorithm used would be implemented in the corresponding .c file.
 *
 * @param adjacencyList[] An array of Node pointers representing the graph's adjacency lists.
 */
void sortAdjacencyLists(Node* adjacencyList[]);

/**
 * @brief Performs a Breadth-First Search (BFS) traversal starting from a given vertex.
 *
 * This function explores the graph level by level, starting from 'startIndex'.
 * It typically uses a queue to manage the vertices to visit. It prints the order
 * in which vertices are visited during the BFS traversal.
 *
 * @param adjacencyList[] An array of Node pointers representing the graph's adjacency lists.
 * @param startIndex The integer ID of the vertex from which the BFS traversal will begin.
 */
void bfs(Node* adjacencyList[], int startIndex);

/**
 * @brief Frees all dynamically allocated memory associated with the graph's adjacency lists.
 *
 * This function iterates through each adjacency list in the 'adjacencyList' array
 * and frees all the 'Node' structures within them. It is crucial to call this
 * function to prevent memory leaks when the graph is no longer needed.
 *
 * @param adjacencyList[] An array of Node pointers representing the graph's adjacency lists.
 */
void freeGraph(Node* adjacencyList[]);

#endif // GRAPH_ALGORITHMS_H