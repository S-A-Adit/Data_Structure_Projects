package project_4;

/**
 * Represents a single node within a linked list data structure.
 * Each node holds an integer value (key) and a reference to the next node in the sequence,
 * enabling it to behave as a fundamental building block for linked lists.
 *
 * @author Adit
 * @version 1.0
 * @since 2025-03-04
 */
public class Node {
	// The integer value stored within this node.
	private int key;
	// A reference to the next node in the linked list.
	// If this is the last node, 'next' will be null.
	private Node next;


	/**
	 * Constructs a new Node with its 'next' reference initialized to null.
	 * The 'key' field remains at its default integer value (0) until explicitly set.
	 */
	public Node() {
		this.next = null;
	}

	/**
	 * Constructs a new Node with a specified integer item.
	 * The 'next' reference is automatically initialized to null,
	 * indicating that this node does not yet point to another node.
	 *
	 * @param item The integer value to be stored in this node.
	 */
	public Node(int item) {
		this.next = null; // A new node initially points to nothing.
		this.key = item;  // Set the integer value for this node.
	}


	/**
	 * Returns the next node in the sequence.
	 * This method allows traversal through the linked list.
	 *
	 * @return The Node that this current node points to, or {@code null} if this is the last node.
	 */
	public Node MoveNext() {
		return this.next;
	}

	/**
	 * Sets the 'next' reference of this node to a specified node.
	 * This method is used to link nodes together, building the list.
	 *
	 * @param theNext The Node to which this current node should point.
	 * @return The Node that was just set as the 'next' reference (i.e., {@code theNext}).
	 */
	public Node SetNext(Node theNext) {
		this.next = theNext;
		return this.next; // Return the node that was just set.
	}


	/**
	 * Prints the integer value (key) of this node to the console.
	 * It does not print a newline character, allowing multiple items to be printed on the same line.
	 */
	public void PrintItem() {
		System.out.print(this.key + " "); // Added a space for better separation during printing.
	}
}