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
    unordered_map<int, int> ind;
    int pind;
    TreeNode* construct(vector<int>& inorder, vector<int>& preorder, int iind, int eind){
        if(iind>eind) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pind++]);
        root->left = construct(inorder, preorder, iind, ind[root->val]-1);
        root->right = construct(inorder, preorder, ind[root->val]+1, eind);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)   ind[inorder[i]] = i;
        pind = 0;
        return construct(inorder, preorder, 0, inorder.size()-1);
        
    }
};