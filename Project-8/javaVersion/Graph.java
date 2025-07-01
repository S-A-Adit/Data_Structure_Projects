

public class Graph {
 private static final int MAX_VERTICES = 10;
 private Node[] adjacencyList;

 public Graph() {
   adjacencyList = new Node[MAX_VERTICES];
  }

    /**
     * Adds an undirected edge between two vertices.
     */
    public void addEdge(int fromIndex, int toIndex) {
        Node newNode = new Node(toIndex);
        newNode.next = adjacencyList[fromIndex];
        adjacencyList[fromIndex] = newNode;
    }

    /**
     * Sorts the adjacency list for each vertex using insertion sort.
     */
    public void sortAdjacencyLists() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            Node sorted = null;
            Node current = adjacencyList[i];

            while (current != null) {
                Node next = current.next;
                sorted = insertSorted(sorted, current);
                current = next;
            }

            adjacencyList[i] = sorted;
        }
    }

    /**
     * Helper method to insert a node into a sorted linked list.
     */
    private Node insertSorted(Node head, Node nodeToInsert) {
        if (head == null || nodeToInsert.vertex < head.vertex) {
            nodeToInsert.next = head;
            return nodeToInsert;
        }

        Node current = head;
        while (current.next != null && current.next.vertex < nodeToInsert.vertex) {
            current = current.next;
        }

        nodeToInsert.next = current.next;
        current.next = nodeToInsert;
        return head;
    }

    /**
     * Performs BFS traversal starting from the given start index (e.g., 0 for 'A').
     */
    public void bfs(int startIndex) {
        boolean[] visited = new boolean[MAX_VERTICES];
        Queue queue = new Queue();

        visited[startIndex] = true;
        queue.enqueue(startIndex);

        while (!queue.isEmpty()) {
            int currentVertex = queue.dequeue();
            System.out.print((char)(currentVertex + 'A') + " ");

            Node currentNode = adjacencyList[currentVertex];
            while (currentNode != null) {
                int neighbor = currentNode.vertex;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.enqueue(neighbor);
                }
                currentNode = currentNode.next;
            }
        }

        System.out.println();
        queue.freeQueue();
    }

    /**
     * Frees all nodes in the adjacency list (helps with GC).
     */
    public void freeGraph() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            Node current = adjacencyList[i];
            while (current != null) {
                Node temp = current;
                current = current.next;
                temp.next = null;  // Help GC
            }
            adjacencyList[i] = null;
        }
    }    
}
