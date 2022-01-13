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
    bool isValidBST(TreeNode* root) {
        in(root);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1])  return false;
        }
        return true;
    }
};