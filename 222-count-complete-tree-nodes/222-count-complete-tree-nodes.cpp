/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int lheight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->left;
        }
        return count;
    }
    int rheight(TreeNode* root){
        int count = 0;
        while(root){
            count++;
            root = root->right;
        }
        return count;
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int l = lheight(root);
        int r = rheight(root);
        
        if(l == r){
            return pow(2, l)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};