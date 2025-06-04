/* Adit Syed Afnan
Data Structures CSCI-230
Project 9
5/6/2025 
This is the header file for project 9.
*/

typedef struct Node
{
	int vertex;
	struct Node* next;
} Node;

void addEdge(Node* adjacencyList[], int fromIndex, int toIndex);
void sortAdjacencyLists(Node* adjacencyList[]);
void bfs(Node* adjacencyList[], int startIndex);
void freeGraph(Node* adjacencyList[]);
