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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0)  return head;
        if(head == NULL)    return NULL;
        ListNode* curr = head;
        ListNode* rot = NULL;
        ListNode* first = head;
        ListNode* second = head;
        ListNode* last = NULL;
        int total = 0;
        while(curr){
            total++;
            curr = curr->next;
        }
        k%=total;
        if(k == 0)  return head;
        int cut = total-k;
        int count = 0;
        while(first){
            count++;
            if(count == cut){
                rot = first->next;
                first->next = NULL;
                break;
            }
            first = first->next;
        }
        second = rot;
        // cout<<first->val<<endl;
        // cout<<rot->val<<endl;
        count = 0;
        while(second->next && count<k){
            cout<<second->val<<endl;
            second = second->next;
            count++;
        }
        second->next = head;;
        return rot;
        
    }
};