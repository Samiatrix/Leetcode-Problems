class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(256, 0);
        for(auto i:s)   count[i]++;
        sort(s.begin(), s.end(), [&](char a, char b){
            return count[a] > count[b] || (count[a] == count[b] && a<b);
        });
        return s;
        map<char, int> mp;
        for(auto i:s)   mp[i]++;
        
        vector<vector<char>> buc(s.size()+1);
        
        for(auto i:mp){
            buc[i.second].push_back(i.first);
        }
        
        string ans = "";
        for(int i=buc.size()-1;i>=0;i--){
            if(buc[i].size() != 0){
                for(auto j:buc[i]){
                    ans+=string(i, j);
                }
            }
        }
        return ans;
        
        vector<pair<int, char>> vec;
        for(auto i:mp){
            vec.push_back({i.second, i.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int, char>>());
        for(auto i:vec){
            char val = i.second;
            int freq = i.first;
            while(freq--){
                ans+=val;
            }
        }
        
        return ans;
    }
};