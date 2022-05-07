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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        int count = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + count;
            count = sum > 9 ? 1 : 0;
            ans->next = new ListNode(sum%10);
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + count;
            count = sum > 9 ? 1 : 0;
            ans->next = new ListNode(sum%10);
            ans = ans->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + count;
            count = sum > 9 ? 1 : 0;
            ans->next = new ListNode(sum%10);
            ans = ans->next;
            l2 = l2->next;
        }
        while(count){
            ans->next = new ListNode(count);
            ans = ans->next;
            count = 0;
        }
        return dummy->next;
    }
};