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
        if(!root)   return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;
        while(!q.empty()){
            int s = q.size();
            vector<int> t(s);
            int i = left ? 0 : s-1;
            while(s--){
                auto curr = q.front();
                q.pop();
                t[i] = curr->val;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                left ? i++ : i--;
            }
            left = !left;
            ans.push_back(t);
        }
        return ans;
    }
};