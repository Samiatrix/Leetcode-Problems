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
    void pre(TreeNode* root, vector<int>& ans){
        if(!root)   return ;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        while(root){
            if(root->right) s.push(root->right);
            ans.push_back(root->val);
            root = root->left;
            if(!root && !s.empty()){
                root = s.top();
                s.pop();
            }
        }
        // pre(root, ans);
        return ans;
    }
};