package Sorting; // Package declaration

import java.util.Scanner; // Import the Scanner class for user input

/*
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * January 29, 2025
 * This program sorts an array of 10 numbers using the Selection Sort algorithm.
 */

public class SelectionSort {

    public static void main(String[] args) {

        // Declare an array to hold 10 integer numbers
        int[] numbersToSort = new int[10];
        // Create a Scanner object to read user input
        Scanner keyboardInput = new Scanner(System.in);

        System.out.println("Please enter 10 integer numbers:");

        // Loop to get 10 numbers from the user and store them in the array
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter number " + (i + 1) + ": "); // Prompt for each number
            String input = keyboardInput.nextLine(); // Read the input as a string
            int number = Integer.parseInt(input);    // Convert the string to an integer
            numbersToSort[i] = number;               // Store the number in the array
        }

        // --- Selection Sort Algorithm ---
        // Outer loop: Iterate through the array to find the minimum element
        // and place it at the correct sorted position.
        for (int i = 0; i < numbersToSort.length - 1; i++) {
            // Assume the current element is the minimum
            int minIndex = i;

            // Inner loop: Find the actual minimum element in the unsorted part of the array
            for (int j = i + 1; j < numbersToSort.length; j++) {
                // If a smaller element is found, update minIndex
                if (numbersToSort[j] < numbersToSort[minIndex]) {
                    minIndex = j;
                }
            }

            // Swap the found minimum element with the element at the current position (i)
            // This places the smallest unsorted element into its correct sorted position
            int temp = numbersToSort[minIndex];      // Temporarily hold the smallest number
            numbersToSort[minIndex] = numbersToSort[i]; // Move the larger value to the minIndex position
            numbersToSort[i] = temp;                 // Place the minimum value at the current sorted position (i)
        }
        // --- End of Selection Sort Algorithm ---

        System.out.println("\nHere is the sorted array using Selection Sort:");
        // Loop to print the sorted array
        for (int i = 0; i < numbersToSort.length; i++) {
            System.out.print(numbersToSort[i] + "  "); // Print each element followed by two spaces
        }
        System.out.println(""); // Print a new line at the end

        keyboardInput.close(); // Close the scanner to release system resources
    }
}