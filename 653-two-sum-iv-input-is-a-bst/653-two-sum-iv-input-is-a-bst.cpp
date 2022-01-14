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
    vector<int> in;
    void inorder(TreeNode* root){
        if(!root)   return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    bool find(TreeNode* root, TreeNode* curr, int t){
        if(root == NULL)    return false;
        
        return (root->val == t && root != curr) || find(root->left, curr, t) || find(root->right, curr, t);
    }
    bool dfs(TreeNode* root, TreeNode* curr, int k){
        if(!curr)   return false;
        
        return find(root, curr, k-(curr->val)) || dfs(root, curr->left, k) || dfs(root, curr->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root, k);
    }
};