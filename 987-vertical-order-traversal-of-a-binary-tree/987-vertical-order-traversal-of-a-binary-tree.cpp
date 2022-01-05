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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<vector<int>> ans;
        int count = 0;
        while(!q.empty()){
            int s = q.size();
            for(int h = 0;h<s;h++){
                int pos = q.front().second;
                TreeNode* t = q.front().first;
                q.pop();
                mp[pos][count].push_back(t->val);
                if(t->left) q.push({t->left, pos-1});
                if(t->right)    q.push({t->right, pos+1});
            }
            count++;
        }
        for(auto i:mp){
            vector<int> t;
            for(auto j:i.second){
                vector<int> g = j.second;
                sort(g.begin(), g.end());
                for(auto k:g)    t.push_back(k);
            }
            ans.push_back(t);
        }
        return ans;
    }
};