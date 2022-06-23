class Solution {
public:
    void print(unordered_map<int, vector<int>>& mp){
        for(auto i:mp){
            cout<<i.first<<" : ";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)  return {0};
        unordered_map<int, vector<int>> mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        
        print(mp);
        
        queue<int> q;
        
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            indegree[i] = mp[i].size();
            if(indegree[i] == 1)    q.push(i);
        }
        
        int count = n;
        
        while(count>2){
            int len = q.size();
            count-=len;
            while(len--){
                auto curr = q.front();
                q.pop();
                for(auto i:mp[curr]){
                    indegree[i]--;
                    if(indegree[i] == 1){
                        q.push(i);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};