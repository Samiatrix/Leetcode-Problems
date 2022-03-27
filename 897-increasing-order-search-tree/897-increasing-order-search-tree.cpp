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
    TreeNode* inorder(TreeNode* root){
        if(root == NULL)    return NULL;
        if(root && root->left == NULL && root->right == NULL)    return root;
        TreeNode* curr = NULL;
        if(root->left)  curr = inorder(root->left);
        TreeNode* childOfRight = NULL;
        if(root->right) childOfRight = inorder(root->right);
        root->left = NULL;
        root->right = childOfRight;
        if(curr && curr->left)  curr->left = NULL;
        if(curr && curr->right) curr->right = root;
        
        return curr;
        // curr->right = root;
        // if(curr->right) curr = curr->right;
        // curr->right = inorder(root->right);
    }
    void inorder(TreeNode* root, vector<TreeNode*>& in){
        if(root == NULL)    return;
        
        if(root->left)  inorder(root->left, in);
        in.push_back(root);
        if(root->right) inorder(root->right, in);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        TreeNode* newRoot = NULL;
        TreeNode* ans;
        for(auto curr : in){
            if(!newRoot){
                newRoot = curr;
                ans = newRoot;
            }
            else{
                newRoot->right = curr;
                newRoot = newRoot->right;
            }
            newRoot->left = NULL;
        }
        return ans;
    }
};