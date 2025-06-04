package project_4;
/*Adit 
Data Structures CSCI-230
Project 4
3/4/2025 
List Class uses node to point item 
*/
public class List {
	private Node head;

	public List() {
		this.head = null;
	}
	
public Node Add(int item) {
	Node newNode = new Node(item);
	if (head == null) {
		this.head = new Node(item); // Create a new node and set it as head
			
	}else {
		Node current = head;
		while (current.MoveNext() != null) {
               current = current.MoveNext();
            }
            current.SetNext(newNode);
		}
		return newNode;
	}
	
public void Print() {
	Node current = head;
	while (current != null) {
		current.PrintItem();
		current = current.MoveNext();
		}
	System.out.println();
	}
}
