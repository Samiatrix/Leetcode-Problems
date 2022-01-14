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
class BSTIterator {
public:
    vector<int> in;
    int ind = 0;
    stack<TreeNode*> s;
    void pushh(TreeNode* root){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushh(root);
        // stack<TreeNode*> s;
        // while(root || !s.empty()){
        //     while(root){
        //         s.push(root);
        //         root = root->left;
        //     }
        //     root = s.top();
        //     s.pop();
        //     in.push_back(root->val);
        //     root = root->right;
        // }
    }
    
    int next() {
        TreeNode* curr = s.top();
        s.pop();
        int n = curr->val;
        pushh(curr->right);
        return n;
        // return in[ind++];
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */