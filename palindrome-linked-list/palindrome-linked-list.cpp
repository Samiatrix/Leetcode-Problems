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
    ListNode* reverse(ListNode* root){
        ListNode* temp = NULL;
        while(root){
            ListNode* headNext = root->next;
            root->next = temp;
            temp = root;
            root = headNext;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        // ListNode* h = head;
        // stack<ListNode*> s;
        // while(h){
        //     s.push(h);
        //     h = h->next;
        // }
        // h = head;
        // while(h){
        //     if(h->val!=s.top()->val)  return false;
        //     s.pop();
        //     h = h->next;
        // }
        // return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast!=NULL)  slow = slow->next;
        slow = reverse(slow);
        fast = head;
        while(slow){
            if(slow->val != fast->val)  return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};