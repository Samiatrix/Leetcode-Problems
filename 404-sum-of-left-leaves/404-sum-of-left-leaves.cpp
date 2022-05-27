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
    int sum(TreeNode* root){
        if(!root)   return 0;
        int ans = 0;
        if(root->left && root->left->left == NULL && root->left->right == NULL)   ans += root->left->val;
        int le = sum(root->left);
        int ri = sum(root->right);
        return le+ri+ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root);
    }
};