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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int count = 0;
        // ListNode* dummy = new ListNode();
        // dummy->next = head;
        // ListNode* first = dummy;
        // ListNode* second = dummy;
        // while(second){
        //     if(count>=(n+1))    first = first->next;
        //     second = second->next;
        //     count++;
        // }
        // first->next = first->next->next;
        // return dummy->next;
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;i++)    fast = fast->next;
        if(fast == NULL)  return head->next;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};