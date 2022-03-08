struct compare{
    bool operator()(pair<int, int>& a, pair<int, int>& b){
        return sqrt(pow(a.first, 2)+pow(a.second, 2)) < sqrt(pow(b.first, 2)+pow(b.second, 2));
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(auto i:points){
            pq.push({i[0], i[1]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return ans;
        
    }
};