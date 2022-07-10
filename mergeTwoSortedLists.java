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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode ret = new ListNode(-1);
        ListNode prev = ret;
        
        while (list1 != null && list2 != null) {
            
            if (list1.val <= list2.val) {
                ListNode tmp = list1.next;
                list1.next = list2;
                prev.next = list1;
                
                prev = list1;
                list1 = tmp;
            } else {
                ListNode tmp = list2.next;
                list2.next = list1;
                prev.next = list2;
                
                prev = list2;
                list2 = tmp;
            }
        }
        
        prev.next = (list1 == null) ? list2 : list1;
        
        return ret.next;
    }
}
