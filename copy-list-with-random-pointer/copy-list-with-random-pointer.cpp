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
        int curr = 0;
        unordered_map<Node*, Node*> mp;
        Node* h = head;
        Node* dummy = new Node(0);
        Node* res = dummy;
        while(h){
            Node* t = new Node(h->val);
            // if(h->random)   cout<<h->random->val<<endl;
            mp[h] = t;
            t->next = h->next;
            res->next = t;
            res = res->next;
            h = h->next;
        }
        h = head;
        res = dummy->next;
        // for(auto i:mp){
        //     cout<<i.first<<", "<<i.second->val<<endl;
        // }
        while(h){
            // cout<<h->val<<" : "<<res->val<<" : ";
            if(h->random == NULL)   res->random = NULL;
            else{
                Node* v = h->random;
                // cout<<v;
                res->random = mp[v];
            }
            // cout<<endl;
            res=res->next;
            h = h->next;
        }
        // for(auto i:mp){
        //     cout<<i.first<<", "<<i.second->val<<endl;
        // }
        curr = 0;
        return dummy->next;
    }
};