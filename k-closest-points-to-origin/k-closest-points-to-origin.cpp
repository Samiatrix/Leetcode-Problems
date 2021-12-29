class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double, vector<pair<int, int>>> mp;
        for(int i=0;i<points.size();i++){
            // cout<<points[i][0]<<", "<<points[i][1]<<" : ";
            double dist = sqrt(pow(points[i][0], 2)+pow(points[i][1], 2));
            // cout<<dist<<endl;
            mp[dist].push_back({points[i][0], points[i][1]});
        }
        vector<vector<int>> ans;
        for(auto i:mp){
            // cout<<i.first<<" : ";
            for(auto j:i.second){
                // cout<<j.first<<", "<<j.second<<endl;
                ans.push_back({j.first, j.second});
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};