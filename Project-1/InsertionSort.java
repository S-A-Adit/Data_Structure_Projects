package Sorting;
import java.util.Scanner;
import java.util.ArrayList;
/* Adit, Syed Afnan 
Data Structures CSCI-230
1/29/2025
This program sorts an ArrayList of 10 numbers using Insertion sort algorithm
*/


public class InsertionSort {
	public static void main(String[] args) {
		ArrayList<Integer> insertsort = new ArrayList<Integer>();
		Scanner keyboard = new Scanner(System.in);
		
		System.out.println("Enter 10 integer numbers: ");
		
		for (int i=0; i<10; i++) { // Here a number is used because size is initially set to 0.
			System.out.print("Enter a number: ");
			String input = keyboard.nextLine();
			int number = Integer.parseInt(input);
			insertsort.add(number);
			
		}
		
		
		for(int i=1; i<insertsort.size(); i++) {
		    int currentspace = insertsort.get(i); // holds value for comparing
		 
			int index = i-1; // reading the array from 1 index backwards
			
			while(index>=0 && insertsort.get(index)>currentspace) {
				insertsort.set(index+1, insertsort.get(index) );
				index--;
			}
			insertsort.set(index+1, currentspace); // Here j is the value at the i-1 as a result of decrement
			
		}
		System.out.println("Here we have the sorted array using Insertion Sort!");
	    System.out.print(insertsort);
	    System.out.println("");
	    
		
	}
}
