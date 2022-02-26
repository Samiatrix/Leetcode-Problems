class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int, int> mp;
        int curr = 0;
        for(int i=0, j=0;j<fruits.size();j++){
            mp[fruits[j]]++;
            curr++;
            while(mp.size()>2){
                if(mp[fruits[i]] == 1)  mp.erase(fruits[i]);
                else    mp[fruits[i]]--;
                curr--;
                i++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};