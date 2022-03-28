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
    vector<TreeNode*> tree(int l, int r){
        if(l>r) return{NULL};
        vector<TreeNode*> ans;
        for(int i=l;i<=r;i++){
            vector<TreeNode*> left = tree(l, i-1);
            vector<TreeNode*> right = tree(i+1, r);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = left[j];
                    curr->right = right[k];
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)  return {};
        return tree(1, n);
    }
};