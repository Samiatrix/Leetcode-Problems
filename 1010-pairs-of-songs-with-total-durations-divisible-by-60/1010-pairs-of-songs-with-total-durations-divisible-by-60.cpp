class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<time.size();i++){
            int t = time[i]%60;
            if(t == 0){
                ans+=mp[t];
            }
            else{
                ans+=mp[60-t];
            }
            mp[t]++;
        }
        return ans;
    }
};