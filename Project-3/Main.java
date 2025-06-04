package project_4;
import java.util.Scanner;
/*Adit 
Data Structures CSCI-230
Project 4
3/4/2025 
This is where the code runs and it is the main
*/
public class Main {
public static void main(String[] args) {
	 Scanner theScanner = new Scanner(System.in);  // Create a Scanner object
	 List theList = new List();
	 System.out.print("Enter a really large integer: ");
	 String inputline = theScanner.nextLine();
	 for(char theChar:inputline.toCharArray()) {
		 	theList.Add(theChar - '0');
	   }
	  	System.out.print("Here is your really large integer:");
	 	theList.Print();
	    System.out.println();
	    theScanner.close();	   
	    
	}
}
