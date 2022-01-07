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
//     TreeNode* lca(TreeNode* root, TreeNode* a, TreeNode* b){
//         if(root == NULL)    return NULL;
        
//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root->val == p->val || root->val == q->val)  return root;
        TreeNode* lcaa = lowestCommonAncestor(root->left, p, q);
        TreeNode* lcab = lowestCommonAncestor(root->right, p, q);
        if(!lcaa)   return lcab;
        else if(!lcab)  return lcaa;
        return root;
        
    }
};