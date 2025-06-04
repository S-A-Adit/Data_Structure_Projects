package project_4;

/**
 * Represents a simple singly linked list data structure.
 * This class allows adding integer items to the list and printing its contents.
 * Each item is encapsulated within a {@link Node} object.
 *
 * @author Adit
 * @version 1.0
 * @since 2025-03-04
 * @see Node
 */
public class List {
	// The head of the linked list. This node points to the first element in the list.
	private Node head;

	/**
	 * Constructs an empty List.
	 * Initializes the head of the list to null, indicating that the list is empty.
	 */
	public List() {
		this.head = null;
	}

	/**
	 * Adds a new integer item to the end of the list.
	 * If the list is empty, the new item becomes the head.
	 * Otherwise, it traverses to the end of the list and appends the new item.
	 *
	 * @param item The integer value to be added to the list.
	 * @return The newly created Node containing the added item.
	 */
	public Node Add(int item) {
		// Create a new Node object with the given item.
		Node newNode = new Node(item);

		// Check if the list is currently empty.
		if (head == null) {
			// If the list is empty, the new node becomes the head of the list.
			this.head = new Node(item); // Create a new node and set it as head

		} else {
			// If the list is not empty, traverse to the last node.
			Node current = head; // Start from the head of the list.
			// Loop until 'current' points to the last node (i.e., its next node is null).
			while (current.MoveNext() != null) {
				current = current.MoveNext(); // Move to the next node in the list.
			}
			// Once the last node is found, set its 'next' pointer to the new node,
			// effectively adding the new node to the end of the list.
			current.SetNext(newNode);
		}
		// Return the newly added node.
		return newNode;
	}

	/**
	 * Prints all items in the list from head to tail to the console.
	 * Each item is printed, followed by a space. After all items, a newline character is printed.
	 */
	public void Print() {
		Node current = head; // Start traversal from the head of the list.
		// Loop through the list as long as the current node is not null.
		while (current != null) {
			current.PrintItem(); // Call the PrintItem method of the current node to display its value.
			current = current.MoveNext(); // Move to the next node in the list.
		}
		System.out.println(); // Print a newline character after all items have been printed.
	}
}
