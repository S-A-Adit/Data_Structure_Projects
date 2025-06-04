package objoriented;
import java.util.*;
/* Adit Syed Afnan
Data Structures CSCI-230
Project 2
2/18/2025
This is the main where the program is run and the user gets the reversed string against their input.
*/

public class Main {
   public static void main(String [] args) {
	   Stack theQueue = new Stack();
	   Scanner keyboard = new Scanner(System.in);
	   
	   System.out.println("Enter your inconveniently large string: ");
	   
	   String input = keyboard.next();
	   StringBuilder reverseString  = new StringBuilder(); // This is where the magic happens
	   
	   for (int i=0; i<input.length(); i++) {
		   char stackmember = input.charAt(i);
		   theQueue.enQueue(stackmember);
	   }
	   while( !theQueue.isEmpty()) {
		   reverseString.append(theQueue.deQueue());
	   }
	   
	   System.out.println(input);
	   System.out.println(reverseString);  
	   
	   
   }
}
