class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int> mp;
        for(auto word:strs){
            string s = "";
            for(auto i:word){
                s+=i;
                mp[s]++;
            }
        }
        string ans = "";
        vector<string> vec;
        for(auto i:mp){
            if(i.second == strs.size()){
                vec.push_back(i.first);
            }
        }
        for(auto i:vec) ans = max(ans, i);
        return ans;
    }
};