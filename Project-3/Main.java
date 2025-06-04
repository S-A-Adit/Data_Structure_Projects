package project_4;

import java.util.Scanner; // Import the Scanner class to enable reading input from the console.

/**
 * Main class for Project 4 - Data Structures (CSCI-230).
 * This class serves as the primary entry point for the program execution.
 * It demonstrates the functionality of the custom {@link List} class
 * by allowing the user to input a large integer, which is then
 * stored digit by digit in the linked list, and subsequently printed.
 *
 * @author Adit
 * @version 1.0
 * @since 2025-03-04
 * @see List
 * @see Node
 */
public class Main {

    /**
     * The main method is the starting point of the Java application.
     * It orchestrates the process of reading user input, populating a linked list,
     * and displaying the stored data.
     *
     * @param args Command line arguments passed to the program (not utilized in this application).
     */
    public static void main(String[] args) {
        // Initialize a Scanner object to capture user input from the standard input stream (keyboard).
        Scanner theScanner = new Scanner(System.in);

        // Create a new instance of the custom List data structure.
        List theList = new List();

        // Prompt the user to enter a sequence of digits representing a large integer.
        System.out.print("Enter a really large integer: ");

        // Read the entire line of input provided by the user as a String.
        String inputline = theScanner.nextLine();

        // Iterate over each character in the input string.
        // Each character is expected to be a digit.
        for (char theChar : inputline.toCharArray()) {
            // Convert the character digit to its corresponding integer value.
            // Subtracting the ASCII value of '0' from a character digit ('1' to '9')
            // effectively converts it to its numerical equivalent (1 to 9).
            // Add this integer digit to the linked list.
            theList.Add(theChar - '0');
        }

        // Display a message to the user before printing the stored integer.
        System.out.print("Here is your really large integer:");

        // Call the Print method of the List object to display all the digits
        // stored in the linked list, effectively showing the large integer.
        theList.Print();

        // Print an additional blank line for better visual separation in the console output.
        System.out.println();

        // Close the Scanner object to release system resources.
        // This is crucial for preventing resource leaks, especially in long-running applications.
        theScanner.close();
    }
}
