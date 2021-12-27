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
    // ListNode* reverse(ListNode* head, ListNode* ans){
    //     // cout<<head->val<<endl;
    //     if(head->next == NULL){
    //         ans = head;
    //         return head;
    //     }
    //     ListNode* curr = reverse(head->next, ans);
    //     cout<<curr->val<<endl;
    //     head->next = NULL;
    //     curr->next = head;
    //     // head->next = reverseList(head->next);
    //     return curr;
    // }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        while(head){
            ListNode* headNext = head->next;
            head->next = temp;
            temp = head;
            head = headNext;
        }
        return temp;
    }
};