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
    bool valid(TreeNode* root, long& prev){
        if(!root)   return true;
        if(!valid(root->left, prev))    return false;
        if(root->val<=prev)  return false;
        prev = root->val;
        return valid(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        return valid(root, prev);
    }
};