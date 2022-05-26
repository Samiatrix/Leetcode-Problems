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
        bool left = true;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            int i = left ? 0 : s-1;
            vector<int>temp(s);
            while(s--){
                auto curr = q.front();
                q.pop();
                temp[i] = curr->val;
                if(curr->left)  q.push(curr->left);
                if(curr->right)  q.push(curr->right);
                if(left)    i++;
                else    i--;
            }
            ans.push_back(temp);
            left = !left;
        }
        return ans;
    }
};