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
    vector<int> in;
    void inorder(TreeNode* root){
        if(!root)   return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        //iterative with stack
        stack<TreeNode*> s;
        TreeNode* prev = new TreeNode(-1);
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            prev = root;
            k--;
            if(k == 0)  break;
            
            root = root->right;
            
        }
        return prev->val;
        //with recursion O(n) time and space;
        // inorder(root);
        // return in[k-1];
    }
};