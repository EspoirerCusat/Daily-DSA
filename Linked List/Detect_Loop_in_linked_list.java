class Node {
    int data;
    Node next;

    public Node(int x) {
        this.data = x;
        this.next = null;
    }
}

class Solution {
    static boolean detectLoop(Node head) {
  
        // Fast and slow pointers initially points to the head
        Node slow = head, fast = head;

        // Loop that runs while fast and slow pointer are not
        // null and not equal
        while (slow != null && fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            // If fast and slow pointer points to the same node,
            // then the cycle is detected
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }

      public boolean detectLoop2(Node head) {
        if(head == null) return false;
        Node slow = head;
        Node fast = head;
        
        do{
            if(slow.next != null) slow = slow.next;
            else return false;
            if(fast.next != null && fast.next.next != null) fast = fast.next.next;
            else return false;
        }while(slow != fast);
        
        return true;
      }

    public static void main(String[] args) {

        Node head = new Node(1);
        head.next = new Node(3);
        head.next.next = new Node(4);
  
        head.next.next.next = head.next;

        if (detectLoop(head))
            System.out.println("true");
        else
            System.out.println("false");
    }
}
