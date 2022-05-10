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
    bool isCheck(TreeNode* root, TreeNode* sub){
        if(!root && !sub)   return true;
        if(!root || !sub)   return false;
        if(root->val != sub->val)   return false;
        return root->val == sub->val && isCheck(root->left, sub->left) && isCheck(root->right, sub->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isCheck(root, subRoot))  return true;
        if(!root)   return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};