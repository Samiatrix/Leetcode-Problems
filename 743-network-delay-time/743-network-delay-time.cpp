class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto i:times){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        vector<int> dis(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dis[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int dist = curr.first;
            int node = curr.second;
            for(auto it:adj[node]){
                if(dist + it.second < dis[it.first]){
                    dis[it.first] = dist + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        int ans = 0;
        for(int i=1;i<dis.size();i++){
            ans = max(ans, dis[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};