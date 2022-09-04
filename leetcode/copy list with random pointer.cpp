/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        
        map<Node*, Node*> origToCopy;
        Node* retHead;
        Node* curr;
        
        while (head) {
            if (!origToCopy[head]) { // current node is new
                Node* copy = new Node(head->val);
                origToCopy[head] = copy;
                curr = copy;
                
                if (!retHead)
                    retHead = copy;
            }
            
            if (head->random && !origToCopy[head->random]) { // head->random hasn't been seen
                Node* random = new Node(head->random->val);
                curr->random = random;
                origToCopy[head->random] = random;
            } else {
                curr->random = origToCopy[head->random];
            }
            
            if (head->next && !origToCopy[head->next]) { // head->next hasn't been seen
                Node* next = new Node(head->next->val);
                curr->next = next;
                origToCopy[head->next] = next;
            } else { // head->next has been seen
                curr->next = origToCopy[head->next];
            }
            
            curr = curr->next;
            head = head->next;
        }
        
           
        return retHead;
    }
};
