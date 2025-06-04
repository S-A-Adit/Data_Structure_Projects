package project_4;
/*Adit 
Data Structures CSCI-230
Project 4
3/4/2025 
The node class which has a key and next to behave like a real node data structure
*/
public class Node {
  private int key;
  private Node next;
  
  
  public Node() {
	  this.next = null;
  }
  
  public Node(int item) {
	  this.next = null;
	  this.key = item;
  }
  
  
  public Node MoveNext() {
	  return this.next;
  }
  
  public Node SetNext(Node theNext) {
	  this.next = theNext;
	  return this.next;
  }
  
  
  public void PrintItem() {
	 System.out.print(this.key + "");
  }
}
