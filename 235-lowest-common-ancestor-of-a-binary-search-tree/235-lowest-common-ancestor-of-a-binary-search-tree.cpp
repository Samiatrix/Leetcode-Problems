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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if((root->val < p->val) && (root->val< q->val)){
            return lca(root->right, p, q);
        }
        if((root->val > p->val) && (root->val > q->val)){
            return lca(root->left, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
        
        
        //normal LCA
        if(root == NULL)    return NULL;
        if(root->val == p->val || root->val == q->val)    return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l == NULL)   return r;
        else if(r == NULL)  return l;
        return root;
    }
};