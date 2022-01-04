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
    void preorder(TreeNode* root, vector<int>& ans){
        if(!root)   return ;
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        stack<TreeNode*> s;
        while(root){
            ans.push_back(root->val);
            if(root->right) s.push(root->right);
            root = root->left;
            if(!root && !s.empty()){
                root = s.top();
                s.pop();
            }
        }
        return ans;
        // preorder(root, ans);
        // return ans;
    }
};