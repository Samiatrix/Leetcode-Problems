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
    vector<int> inorder;
    void in(TreeNode* root){
        if(!root)   return;
        in(root->left);
        inorder.push_back(root->val);
        in(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // in(root);
        // return inorder;
        stack<TreeNode*> s;
        // s.push(root);
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root = root->left;
            }
            
            if(!s.empty()){
                root = s.top();
                s.pop();
                inorder.push_back(root->val);
                root = root->right;
            }
        }
        return inorder;
    }
};