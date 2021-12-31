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
        int count = 0;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        while(l1 && l2){
            int sum = l1->val + l2->val + count;
            count = 0;
            if(sum>9){
                count = 1;
                sum%=10;
            }
            ListNode* t = new ListNode(sum);
            res->next = t;
            res = res->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = l1->val + count;
            count = 0;
            if(sum>9){
                count = 1;
                sum%=10;
            }
            ListNode* t = new ListNode(sum);
            res->next = t;
            res = res->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + count;
            count = 0;
            if(sum>9){
                count = 1;
                sum%=10;
            }
            ListNode* t = new ListNode(sum);
            res->next = t;
            res = res->next;
            l2 = l2->next;
        }
        if(count){
            ListNode* t = new ListNode(count);
            res->next = t;
            res = res->next;
        }
        return dummy->next;
    }
};