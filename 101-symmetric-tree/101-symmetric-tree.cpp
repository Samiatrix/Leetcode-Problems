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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            auto s = q.front();
            q.pop();
            if(!f && !s)    continue;
            if(!f || !s || f->val != s->val)    return false;
            
            q.push(f->left);
            q.push(s->right);
            q.push(f->right);
            q.push(s->left);
        }
        return true;
    }
};