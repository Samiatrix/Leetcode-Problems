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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        dummy->next = head;
        ListNode* curr = head;
        while(curr){
            if(curr->next && curr->next->val == curr->val){
                while(curr->next && curr->next->val == curr->val)   curr = curr->next;
                ans->next = curr->next;
            }
            else{
                ans = ans->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};