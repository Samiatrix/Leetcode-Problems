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
    void inorder(TreeNode* root, vector<TreeNode*>& in){
        if(!root)   return;
        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }
    TreeNode* create(int l, int r, vector<TreeNode*>& in){
        if(l>r) return NULL;
        int m = l+(r-l)/2;
        TreeNode* root = in[m];
        root->left = create(l, m-1, in);
        root->right = create(m+1, r, in);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        return create(0, in.size()-1, in);
    }
};