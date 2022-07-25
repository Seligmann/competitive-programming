/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        Map<Integer, ListNode> nodes = new HashMap<>();
        nodes.put(-1, new ListNode(-1));
        nodes.put(0, head);
        int i = 1;
        ListNode ret = head;
        head = head.next;
        
        if (head == null) return null;
        if (head.next == null) {
            nodes.put(1, head);
            if (n == 1) {
                ListNode beforeTarget = nodes.get(0);
                beforeTarget.next = null;
                return ret;
            } else if (n == 2) {
                ret = nodes.get(1);
                return ret;
            } else 
                return null;
        }
        
        while (head != null) {
            nodes.put(i, head);
            
            if (head.next == null) {
                ListNode beforeTarget = nodes.get(i - n);
                if (beforeTarget.val == -1) 
                    return ret.next;
                else {
                    if (n == 1)
                        beforeTarget.next = null;
                    else if (n == 2)
                        beforeTarget.next = head;
                    else beforeTarget.next = beforeTarget.next.next;
                    
                    return ret;
                        
                }
            }
            
            i++;
            head = head.next;
            
        }
        
        return ret;
    }
}   
