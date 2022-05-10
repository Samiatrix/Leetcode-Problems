class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> mp;
        for(auto i:p)   mp[i]++;
        
        vector<int> ans;
        int freq = 0;
        for(int i = 0, j = 0;j<s.size();j++){
            if(mp.count(s[j])){
                mp[s[j]]--;
                if(mp[s[j]] == 0)   freq++;
            }
            if(freq == mp.size())   ans.push_back(i);
            
            if(j>=p.size()-1){
                char ch = s[i++];
                if(mp.count(ch)){
                    if(mp[ch] == 0){
                        freq--;
                    }
                    mp[ch]++;
                }
            }
        }
        return ans;
    }
};