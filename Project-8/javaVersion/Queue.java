/**
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 8: Queue Implementation
 * Date: 2025-05-06
 *
 * This file contains the complete implementation of a Queue data structure
 * using a linked list in Java. It includes:
 * - Node definition
 * - Enqueue and dequeue methods
 * - Empty check
 * - Memory management simulated through Java GC
 */

public class Queue {
	  /**
     * Inner class representing a single node in the queue.
     */
    private static class QueueNode {
        int vertex;              // The value stored in this node.
        QueueNode next;          // Pointer to the next node.

        QueueNode(int vertex) {
            this.vertex = vertex;
            this.next = null;
        }
    }

    // Pointer to the front and rear of the queue.
    private QueueNode front;
    private QueueNode rear;

    /**
     * Constructs an empty queue.
     */
    public Queue() {
        this.front = null;
        this.rear = null;
    }

    /**
     * Checks whether the queue is empty.
     * @return true if the queue is empty, false otherwise
     */
    public boolean isEmpty() {
        return front == null;
    }

    /**
     * Adds a new element to the rear of the queue.
     * @param vertex The integer value to add
     */
    public void enqueue(int vertex) {
        QueueNode newNode = new QueueNode(vertex);

        if (rear == null) {
            // Queue is empty, front and rear both point to new node
            front = newNode;
            rear = newNode;
        } else {
            // Link new node to end of queue and update rear
            rear.next = newNode;
            rear = newNode;
        }
    }

    /**
     * Removes and returns the front element of the queue.
     * @return The integer value removed from the front
     * @throws IllegalStateException if the queue is empty
     */
    public int dequeue() {
        if (front == null) {
            throw new IllegalStateException("DEQUEUE found the Queue to be empty!");
        }

        int value = front.vertex;
        front = front.next;

        // If the queue is now empty, set rear to null as well
        if (front == null) {
            rear = null;
        }

        return value;
    }

    /**
     * Frees the queue by removing all elements.
     * Java garbage collection handles memory deallocation.
     */
    public void freeQueue() {
        while (front != null) {
            QueueNode temp = front;
            front = front.next;
            // Help GC by explicitly clearing the link (not strictly required)
            temp.next = null;
        }
        rear = null;
    }
}
