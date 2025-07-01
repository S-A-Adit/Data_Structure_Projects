package project_5;

public class DoublyLinkedList {
	private Node head;
    private Node tail;

    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    /**
     * Adds a new node with the given key to the end of the list.
     */
    public boolean add(int key) {
        Node newNode = new Node(key);
        if (newNode == null) {
            return false;
        }

        if (head == null) {
            // List is empty
            head = newNode;
            tail = newNode;
        } else {
            // Append to the tail
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }

        return true;
    }

    /**
     * Prints the list from head to tail.
     */
    public void printForward() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = head;
        while (current != null) {
            System.out.print(current.key + " ");
            current = current.next;
        }
        System.out.println(); // for newline
    }

    /**
     * Prints the list from tail to head.
     */
    public void printBackward() {
        if (tail == null) {
            System.out.println("List is empty.");
            return;
        }

        Node current = tail;
        while (current != null) {
            System.out.print(current.key + " ");
            current = current.prev;
        }
        System.out.println(); // for newline
    }

}
