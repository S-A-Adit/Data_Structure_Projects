package objoriented;

import java.util.*;

/*
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 2
 * Due: 2/18/2025
 *
 * This class implements a basic Stack data structure using an ArrayList.
 * It manages the number of items on the stack and provides common stack operations.
 *
 * Note: The class name is 'Stack' but some internal variables and comments
 * refer to 'queueHeight' and 'theQueue'. While the functionality
 * mimics a stack (LIFO - Last-In, First-Out) using ArrayList's add/remove from end,
 * standard naming conventions for a stack would typically use 'stackHeight' and 'theStack',
 * and methods like 'push' and 'pop'. This structure has been preserved as per instructions.
 */
public class Stack { // This class is named Stack but implements Queue-like methods
    // Tracks the current number of items in the stack (named 'queueHeight' in original)
    private int queueHeight;
    // The underlying data storage for the stack (named 'theQueue' in original)
    private ArrayList<Character> theQueue;

    /**
     * Constructs an empty Stack.
     * Initializes the stack height to 0 and creates an empty ArrayList.
     */
    public Stack() {
        queueHeight = 0;
        theQueue = new ArrayList<>();
    }

    /**
     * Adds an item to the "stack" (behaves like a push operation for a stack).
     * The item is added to the end of the internal ArrayList.
     *
     * @param item The Character item to be added.
     */
    public void enQueue(Character item) { // This method acts like 'push' for a stack
        theQueue.add(item); // Adds to the end, which is the 'top' of our stack
        queueHeight++; // Increments the count of items
    }

    /**
     * Removes and returns the top item from the "stack" (behaves like a pop operation for a stack).
     * If the stack is empty, it returns 'A' as an indicator (as per original logic).
     *
     * @return The Character item removed from the top of the stack, or 'A' if empty.
     */
    public Character deQueue() { // This method acts like 'pop' for a stack
        if (queueHeight == 0) {
            // Stack is empty, return 'A' as specified by the original logic.
            // In a typical stack implementation, this would throw an exception (e.g., EmptyStackException).
            return ('A');
        } else {
            queueHeight--; // Decrements the count of items
            // Removes the item from the end of the ArrayList, which is the 'top' of our stack.
            return theQueue.remove(queueHeight);
        }
    }

    /**
     * Returns the current number of items in the stack.
     * This method is private in the original code, limiting external access to the height.
     *
     * @return The number of items currently in the stack.
     */
    private int getHeight() {
        return (queueHeight);
    }

    /**
     * Checks if the stack is currently empty.
     *
     * @return true if the stack contains no items, false otherwise.
     */
    public boolean isEmpty() {
        // A more concise way to write this would be 'return queueHeight == 0;'
        if (queueHeight == 0) {
            return true;
        } else {
            return false;
        }
    }
}