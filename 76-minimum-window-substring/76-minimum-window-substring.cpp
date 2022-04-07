class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(auto i:t)   mp[i]++;
        int len = INT_MAX, start = 0, count = t.size();;
        for(int i=0, j=0;j<s.size();j++){
            if(mp[s[j]]-->0){
                count--;
            }
            while(count == 0){
                if(j-i+1 < len){
                    len = j-i+1;
                    start = i;
                }
                
                if(mp[s[i++]]++ == 0)  count++;
            }
        }
        if(len == INT_MAX)  return "";
        return s.substr(start, len);
    }
};