
public class Main {
  public static void main(String[] args) { 
	  DoublyLinkedList myList = new DoublyLinkedList();
     // Adding elements
	 myList.add(10);
	 myList.add(20);
	 myList.add(30);

	// Print list forward
	System.out.println("Printing list forward:");
	myList.printForward();

    // Print list backward
	System.out.println("Printing list backward:");
	myList.printBackward();
 }
}
