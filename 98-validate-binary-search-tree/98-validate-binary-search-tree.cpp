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
    TreeNode* prev = NULL;
    void in(TreeNode* root){
        if(!root)   return;
        in(root->left);
        inorder.push_back(root->val);
        in(root->right);
    }
    bool ino(TreeNode* root){
        if(!root)   return true;
        bool l = ino(root->left);
        if(prev && prev->val>=root->val)   return false;
        prev = root;
        bool r = ino(root->right);
        return l&&r;
    }
    bool isValidBST(TreeNode* root) {
        return ino(root);
        stack<TreeNode*> s;
        // s.push(root);
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            inorder.push_back(root->val);
            root = root->right;
        }
        
        // in(root);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1])  return false;
        }
        return true;
    }
};