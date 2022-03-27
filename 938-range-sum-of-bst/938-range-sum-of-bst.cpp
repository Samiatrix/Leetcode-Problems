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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL)    return 0;
        // return (low <= root->val && root->val <= high ? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        
        stack<TreeNode*> s;
        s.push(root);
        int ans = 0;
        while(!s.empty()){
            auto curr = s.top();
            s.pop();
            if(curr == NULL)    continue;
            if(curr->val > low) s.push(curr->left);
            if(curr->val < high)   s.push(curr->right);
            if(low <= curr->val && curr->val <= high)   ans+=curr->val;
        }
        return ans;
    }
};