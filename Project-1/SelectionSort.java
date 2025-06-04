package Sorting;
import java.util.Scanner;
/* Adit Syed Afnan 
Data Structures CSCI-230
1/29/2025
This program sorts an array of 10 numbers using selection sort algorithm
*/


public class SelectionSort {
	public static void main(String[] args) {
		
	int selectionsort [] = new int[10];	
	Scanner keyboard = new Scanner(System.in);
	

	System.out.println("Enter 10 integer numbers: ");
	
	for(int i = 0; i<10 ; i++) {
		System.out.print("Enter a number: ");
		String input = keyboard.nextLine();
		int number = Integer.parseInt(input);
		selectionsort[i] = number;
	}
	
    for (int i =0; i<selectionsort.length - 1; i++) {
    	int minvalueindex = i;
    	
    	
    	for (int j= i + 1; j < selectionsort.length; j++) { // Reads through the entire array
    		
    		if (selectionsort[j] < selectionsort[minvalueindex] ) { // Finds the lower value index after each interation
    			minvalueindex = j;
    		}	
    	}
    	int space = selectionsort[minvalueindex]; // Hold the smallest number 
    	selectionsort[minvalueindex]= selectionsort[i];// Larger value is being put in the smaller index
    	selectionsort[i] = space; // Minimum value at the lowest index
    	
    }
    
    System.out.println("Here we have the sorted array using Selection Sort!");
    for (int i=0; i<selectionsort.length; i++) {
    	System.out.print(selectionsort[i] + "  ");	
    }
    System.out.println("");
	
}
}
