package Sorting; // Package declaration for organization

import java.util.Scanner; // Imports the Scanner class to get user input
import java.util.ArrayList; // Imports the ArrayList class for dynamic array functionality

/*
 * Adit, Syed Afnan
 * Data Structures CSCI-230
 * 1/29/2025
 * This program sorts an ArrayList of 10 numbers using the Insertion Sort algorithm.
 */

public class InsertionSort {
    public static void main(String[] args) {
        // Create an ArrayList to store the integers for sorting
        ArrayList<Integer> numbersToSort = new ArrayList<Integer>();
        // Create a Scanner object to read input from the console
        Scanner keyboard = new Scanner(System.in);

        System.out.println("Enter 10 integer numbers:");

        // Loop to prompt the user for 10 integer inputs and add them to the ArrayList
        for (int i = 0; i < 10; i++) {
            System.out.print("Enter a number: ");
            String input = keyboard.nextLine(); // Read the user's input as a string
            int number = Integer.parseInt(input); // Convert the string input to an integer
            numbersToSort.add(number); // Add the integer to the ArrayList
        }

        // --- Insertion Sort Algorithm ---
        // Iterate through the ArrayList starting from the second element (index 1)
        // The first element (index 0) is considered already sorted
        for (int i = 1; i < numbersToSort.size(); i++) {
            // 'currentValue' holds the element to be inserted into the sorted portion
            int currentValue = numbersToSort.get(i);

            // 'j' is the index of the last element in the sorted portion
            int j = i - 1;

            // Move elements of numbersToSort[0..i-1], that are greater than currentValue,
            // to one position ahead of their current position
            while (j >= 0 && numbersToSort.get(j) > currentValue) {
                numbersToSort.set(j + 1, numbersToSort.get(j)); // Shift element to the right
                j--; // Move to the previous element in the sorted portion
            }
            // Place 'currentValue' at its correct position in the sorted portion
            numbersToSort.set(j + 1, currentValue);
        }

        System.out.println("Here we have the sorted array using Insertion Sort!");
        System.out.print(numbersToSort); // Print the sorted ArrayList
        System.out.println(); // Print a new line for better formatting
    }
}