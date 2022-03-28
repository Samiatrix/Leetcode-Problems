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
        TreeNode* curr = root;
        while(curr && curr->left){
            curr = curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)    return NULL;
        // if(root->val == key)    return NULL;
        TreeNode* newRoot = root;
        if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else{
            if(root->left == NULL){
                return root->right;
            }
            else if(root->right == NULL){
                return root->left;
            }
            else{
                TreeNode* temp = inorder(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return newRoot;
    }
};