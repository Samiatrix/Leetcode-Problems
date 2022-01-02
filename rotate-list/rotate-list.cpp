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
        ListNode* first = head;
        
        int total = 1;
        while(curr->next){
            total++;
            curr = curr->next;
        }
        
        k%=total;
        cout<<k<<endl;
        if(k == 0)  return head;
        ListNode* tail = curr;
        tail->next = head;
        int cut = total-k-1;
        while(cut--){
            cout<<first->val<<endl;
            first = first->next;
        }
        ListNode* ans = first->next;
        first->next = NULL;
        return ans;
    }
};