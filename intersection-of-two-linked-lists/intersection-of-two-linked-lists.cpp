/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode*> s;
        // while(headA){
        //     s.insert(headA);
        //     headA = headA->next;
        // }
        // while(headB){
        //     if(s.count(headB)) return headB;
        //     headB = headB->next;
        // }
        // return NULL;
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        if(l1 == l2)    return l1;
        while(l1 && l2 && l1!=l2){
            l1 = l1->next;
            l2 = l2->next;
            
            if(l1 == l2)    return l1;
            
            if(!l1) l1 = headA;
            if(!l2) l2 = headB;
        }
        return l1;
    }
};