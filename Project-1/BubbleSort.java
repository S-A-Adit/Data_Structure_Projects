package Sorting;
import java.util.Scanner;
/* Adit Syed Afnan 
Data Structures CSCI-230
1/29/2025
This program sorts an array of 10 numbers using optimized bubble sort algorithm
*/


public class BubbleSort {
	public static void main(String[] args) {
		int bubblesort [] = new int[10];	
		Scanner keyboard = new Scanner(System.in);
		

		System.out.println("Enter 10 integer numbers: ");
		
		for(int i = 0; i<10 ; i++) {
			System.out.print("Enter a number: ");
			String input = keyboard.nextLine();
			int number = Integer.parseInt(input);
			bubblesort[i] = number;
		}
		boolean swapped = false;
		int numSwaps = 0;
		
		while (!swapped){ 
			swapped = true;
			
			
			for(int j=0; j<bubblesort.length-1-numSwaps; j++ ) {// i elements are already sorted so reduces number of comparisons
				if (bubblesort[j]> bubblesort[j+1]) { 
					int currentspace = bubblesort[j]; // Larger value is stored
					bubblesort[j] = bubblesort[j+1]; // Smaller value goes to the left index 
					bubblesort[j+1] =  currentspace; // Larger value goes to the right index 
					swapped = false;
				}
			}
			
			numSwaps++;
		}
	    
		System.out.println("Here we have the sorted array using Optimized Bubble Sort!");
	    for (int num=0; num<bubblesort.length; num++) {
	    	System.out.print(bubblesort[num] + "  ");
	    }
	    System.out.println("");
		
	}
}
