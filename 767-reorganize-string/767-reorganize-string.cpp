class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;
        for(auto i:s)   mp[i]++;
        priority_queue<pair<int, char>> pq;
        for(auto i:mp){
            pq.push({i.second, i.first});
        }
        string ans = "";
        while(pq.size()>=2){
            auto f = pq.top();
            pq.pop();
            ans+=f.second;
            auto s = pq.top();
            pq.pop();
            ans+=s.second;
            if(f.first>1)   pq.push({f.first-1, f.second});
            if(s.first>1)   pq.push({s.first-1, s.second});
        }
        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        if(s.size()!=ans.size())    return "";
        return ans;
    }
};