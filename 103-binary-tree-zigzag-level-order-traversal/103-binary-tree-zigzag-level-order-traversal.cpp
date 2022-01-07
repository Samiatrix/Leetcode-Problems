/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int s = q.size();
            vector<int> t;
            while(s--){
                auto p = q.front();
                q.pop();
                t.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right)    q.push(p->right);
            }
            if(flag)    ans.push_back(t);
            else{
                reverse(t.begin(), t.end());
                ans.push_back(t);
            }
            flag = !flag;
        }
        return ans;
    }
};