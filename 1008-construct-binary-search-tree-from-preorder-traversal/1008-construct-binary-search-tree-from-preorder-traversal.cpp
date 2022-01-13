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
    int ind=0;
    TreeNode* construct(vector<int>& preorder, int limit){
        if(ind>=preorder.size() || preorder[ind]>=limit)    return NULL;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = construct(preorder, root->val);
        root->right = construct(preorder, limit);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, INT_MAX);
    }
};