/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* h = head;
        stack<ListNode*> s;
        while(h){
            s.push(h);
            h = h->next;
        }
        h = head;
        while(h){
            if(h->val!=s.top()->val)  return false;
            s.pop();
            h = h->next;
        }
        return true;
    }
};