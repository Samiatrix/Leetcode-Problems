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
    TreeNode* construct(vector<int>& preorder, int l, int r){
        if(l>r) return NULL;
        TreeNode* root = new TreeNode(preorder[l]);
        int rs = -1;
        if(l+1>r)    return root;
        for(int i=l+1;i<=r;i++){
            if(preorder[i]>preorder[l]){
                rs = i;
                break;
            }
        }
        if(l+1<=r && rs == -1){
            root->left = construct(preorder, l+1, r);
            return root;
        }
        // if(rs >= preorder.size()) return root;
        root->left = construct(preorder, l+1, rs-1);
        root->right = construct(preorder, rs, r);
        return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, 0, preorder.size()-1);
    }
};