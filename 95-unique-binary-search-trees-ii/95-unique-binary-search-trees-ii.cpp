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
    vector<TreeNode*> gen(int l, int r){
        if(l>r) return {NULL};
        vector<TreeNode*> ans;
        
        for(int i=l;i<=r;i++){  
            vector<TreeNode*> le = gen(l, i-1);
            vector<TreeNode*> ri = gen(i+1, r);
            
            for(int j=0;j<le.size();j++){
                for(int k=0;k<ri.size();k++){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = le[j];
                    curr->right = ri[k];
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n)  return {};
        return gen(1, n);
    }
};