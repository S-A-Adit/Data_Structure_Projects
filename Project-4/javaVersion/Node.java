
public class Node {
    int key;
    Node next;
    Node prev;

    public Node(int key) {
        this.key = key;
        this.next = null;
        this.prev = null;
    }

    public void printNode() {
        System.out.println("Node key: " + key);
    }
}
