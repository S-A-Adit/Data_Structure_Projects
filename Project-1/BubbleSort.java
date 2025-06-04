package Sorting; // Declares the package for this class

import java.util.Scanner; // Imports the Scanner class for user input

/*
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * 1/29/2025
 * This program sorts an array of 10 numbers using the optimized bubble sort algorithm.
 */

public class BubbleSort {
    public static void main(String[] args) {
        // Declare an array to hold 10 integers for sorting
        int[] numbersToSort = new int[10];
        // Create a Scanner object to read input from the console
        Scanner keyboard = new Scanner(System.in);

        System.out.println("Enter 10 integer numbers:");

        // Loop to get 10 integer inputs from the user
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter a number: ");
            String input = keyboard.nextLine(); // Read the entire line of input
            int number = Integer.parseInt(input); // Convert the input string to an integer
            numbersToSort[i] = number; // Store the number in the array
        }

        // --- Optimized Bubble Sort Algorithm ---
        boolean swapped; // Flag to track if any swaps occurred in a pass
        int passes = 0; // Counter for the number of completed passes (elements sorted)

        // The outer loop continues as long as elements are being swapped
        do {
            swapped = false; // Reset the swapped flag for each new pass

            // Inner loop for comparisons and swaps
            // The `numbersToSort.length - 1 - passes` ensures we don't compare already sorted elements
            for (int j = 0; j < numbersToSort.length - 1 - passes; j++) {
                // Compare adjacent elements
                if (numbersToSort[j] > numbersToSort[j + 1]) {
                    // If the current element is greater than the next, swap them
                    int temp = numbersToSort[j]; // Store the larger value temporarily
                    numbersToSort[j] = numbersToSort[j + 1]; // Move the smaller value to the left
                    numbersToSort[j + 1] = temp; // Place the larger value to the right
                    swapped = true; // Set swapped to true as a swap occurred
                }
            }
            passes++; // Increment the passes counter after each full pass
        } while (swapped); // Continue if at least one swap happened in the last pass

        // --- Display the Sorted Array ---
        System.out.println("Here we have the sorted array using Optimized Bubble Sort!");
        // Loop through the sorted array and print each element
        for (int i = 0; i < numbersToSort.length; i++) {
            System.out.print(numbersToSort[i] + " ");
        }
        System.out.println(); // Print a new line for better formatting
        
        keyboard.close(); // Close the scanner to release system resources
    }
}