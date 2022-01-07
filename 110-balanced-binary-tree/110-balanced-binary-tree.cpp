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
    vector<pair<int, int>> v;
    int height(TreeNode* root){
        if(root == NULL)    return 0;
        int l = height(root->left);
        int r = height(root->right);
        v.push_back({l, r});
        return 1+max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        for(auto i:v){
            if(abs(i.first-i.second) > 1)   return false;
        }
        return true;
    }
};