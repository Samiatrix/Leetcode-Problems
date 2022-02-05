class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mpp;
        for(auto i:s)   mp[i]++;
        int ans = 0;
        int sl = 0, sr = mp.size();
        for(int i=0;i<s.size()-1;i++){
            char ch = s[i];
            if(mp[ch] == 1){
                mp.erase(ch);
                mpp[ch]++;
            }
            else{
                mp[ch]--;
                mpp[ch]++;
            }
            ans += mp.size() == mpp.size();
        }
        return ans;
    }
};