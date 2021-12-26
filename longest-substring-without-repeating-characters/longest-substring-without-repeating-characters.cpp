class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i=0, j=0;j<s.size();j++){
            if(mp[s[j]] >= 1){
                mp[s[i++]]--;
                j--;
            }
            else{
                mp[s[j]]++;
                ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};
        