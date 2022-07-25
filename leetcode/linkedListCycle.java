/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode prev = null;
        Map<ListNode, ListNode> addr = new HashMap<>();
        
        while (head != null) {
            if (addr.containsKey(prev))
                return true;
            else {
                addr.put(prev, head);
                prev = head;
                head = head.next;
            }
        }
        return false;
    }
}
