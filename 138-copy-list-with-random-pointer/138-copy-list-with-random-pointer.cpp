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
        unordered_map<Node*, Node*> nodeToNode;
        Node* dummy = new Node(0);
        Node* ans = dummy;
        Node* curr = head;
        while(curr){
            Node* t = new Node(curr->val);
            nodeToNode[curr] = t;
            curr = curr->next;
            ans->next = t;
            ans = ans->next;
        }
        curr = head;
        ans = dummy->next;
        while(curr){
            ans->random = nodeToNode[curr->random];
            ans = ans->next;
            curr = curr->next;
        }
        return dummy->next;
        
    }
};