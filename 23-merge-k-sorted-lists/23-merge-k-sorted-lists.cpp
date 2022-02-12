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
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)   return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ans->next = curr;
            ans = ans->next;
            if(curr->next){
                curr = curr->next;
                pq.push(curr);
            }
        }
        return res->next;
    }
};