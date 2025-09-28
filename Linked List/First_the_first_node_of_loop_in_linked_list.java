
//Find the first node of loop in linked list
//https://www.geeksforgeeks.org/problems/find-the-first-node-of-loop-in-linked-list--170645/1


class Solution {
    public int cycleStart(Node head) {
        // code here
        if(head == null) return -1;
        Node slow = head;
        Node fast = head;
        
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) break;
        }
        if(fast == null || fast.next == null) return -1;
        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return slow.data;
    }
}
