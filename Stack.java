package objoriented;
import java.util.*;
/* Adit Syed Afnan
Data Structures CSCI-230
Project 2
2/18/2025 
The Queue Class increments and decrements the stack height returns the number of items on the stack.
*/

public class Stack {
	private int queueHeight;
	private ArrayList <Character> theQueue = new ArrayList <>();
    
	
	public Stack(){
		queueHeight = 0;
		theQueue = new ArrayList <Character>();
	}
	
	
	public void enQueue(Character item) {
		theQueue.add(item);
		queueHeight ++;
		
	}
	
	public Character deQueue() {
		if (queueHeight == 0) {
			return ('A');
		}
		else{
			queueHeight --;
			return theQueue.remove(queueHeight);
		}
		
	}
	
	
	private int getHeight() {
		return(queueHeight);
	}
	
	public boolean isEmpty() {
		if (queueHeight == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
 
	
	
	
}
