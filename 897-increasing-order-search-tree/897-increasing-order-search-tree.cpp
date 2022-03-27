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
    TreeNode* curr;
    
    void inorder(TreeNode* root){
        if(root == NULL)    return;
        inorder(root->left);
        root->left = NULL;
        curr->right = root;
        curr = root;
        inorder(root->right);
    }
    
//     void inorder(TreeNode* root, vector<TreeNode*>& in){
//         if(root == NULL)    return;
        
//         if(root->left)  inorder(root->left, in);
//         in.push_back(root);
//         if(root->right) inorder(root->right, in);
//     }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        return ans->right;
        // vector<TreeNode*> in;
        // // inorder(root, in);
        // TreeNode* newRoot = NULL;
        // TreeNode* ans;
        // for(auto curr : in){
        //     if(!newRoot){
        //         newRoot = curr;
        //         ans = newRoot;
        //     }
        //     else{
        //         newRoot->right = curr;
        //         newRoot = newRoot->right;
        //     }
        //     newRoot->left = NULL;
        // }
        // return ans;
    }
};