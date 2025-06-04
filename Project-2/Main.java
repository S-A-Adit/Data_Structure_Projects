
/*
 * Adit Syed Afnan
 * Data Structures CSCI-230
 * Project 2
 * 2/18/2025
 *
 * This is the main class where the program is executed.
 * It takes a string input from the user, reverses it using a Stack,
 * and then displays both the original and the reversed string.
 */
public class Main {
   /**
    * The main method is the entry point of the program.
    * It handles user input, string manipulation using a Stack,
    * and output display.
    *
    * @param args Command line arguments (not used in this program).
    */
   public static void main(String [] args) {
	   // Initialize a Stack to temporarily store characters for reversal.
	   // Note: Although named 'theQueue', this object functions as a Stack (LIFO).
	   Stack theQueue = new Stack();
	   
	   // Create a Scanner object to read user input from the console.
	   Scanner keyboard = new Scanner(System.in);
	   
	   // Prompt the user to enter a string.
	   System.out.println("Enter your inconveniently large string: ");
	   
	   // Read the next token (word) as input from the user.
	   String input = keyboard.next();
	   
	   // Create a StringBuilder to efficiently build the reversed string.
	   StringBuilder reverseString  = new StringBuilder(); // This is where the magic happens
	   
	   // Iterate through each character of the input string.
	   // Each character is pushed onto the stack.
	   for (int i = 0; i < input.length(); i++) {
		   char stackmember = input.charAt(i); // Get character at current index
		   theQueue.enQueue(stackmember);     // Push the character onto the stack
	   }
	   
	   // While the stack is not empty, pop characters and append them to the StringBuilder.
	   // This effectively reverses the order of characters.
	   while( !theQueue.isEmpty()) {
		   reverseString.append(theQueue.deQueue()); // Pop character and append to reversed string
	   }
	   
	   // Print the original string.
	   System.out.println(input);
	   
	   // Print the reversed string.
	   System.out.println(reverseString);
	   
	   // Close the scanner to release system resources.
	   keyboard.close();
   }
}