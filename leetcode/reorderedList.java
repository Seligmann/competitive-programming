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
    public void reorderList(ListNode head) {
        
        ListNode slow = head, fast = head, mid = null, ret = head, beforeMid = null;
        int i = 1;
        
        // Find midpoint
        while (slow != null) {
            if (fast == null) {
                beforeMid.next = null;
                mid = slow;
                
                break;
            } else if (fast.next == null) {
                mid = slow.next;
                slow.next = null;
                break;
            } else {
                beforeMid = slow;
                slow = slow.next;
                fast = fast.next.next;
                i++;
                
            }
        }
        
        ListNode prev = null, midRev = null, stop = mid;
        while (mid != null) {
            ListNode tmp = mid.next;
            ListNode curr = mid;
            mid.next = prev;
            prev = curr;
            mid = tmp;
        }
        midRev = prev;
        
        while (midRev != null) {
            ListNode tmp = head.next;
            ListNode tmp2 = midRev.next;
            head.next = midRev;
            midRev.next = tmp;
            midRev = tmp2;
            head = tmp;
        }
        
        
        
    }
}
