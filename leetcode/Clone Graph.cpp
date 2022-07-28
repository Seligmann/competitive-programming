/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> seen;
    Node* root;
    
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        
        if (seen.count(node->val))
            return seen[node->val];
            
        if (!root) {
            root = new Node(node->val);
            seen[node->val] = root;
                
            for (int i = 0; i < node->neighbors.size(); i++)
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            
        } else {
            Node* newNode = new Node(node->val);
            seen[newNode->val] = newNode;
            
            for (int i = 0; i < node->neighbors.size(); i++)
                newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            
            return newNode;
        }
        
        return root;
    }
};
