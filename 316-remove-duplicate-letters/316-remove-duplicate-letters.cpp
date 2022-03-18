class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq, used;
        string ans = "";
        for(auto i:s){
            freq[i]++;
        }
        for(auto i:s){
            --freq[i];
            if(used[i]++>0) continue;
            while(!ans.empty() && ans.back()>i && freq[ans.back()]>0){
                used[ans.back()] = 0;
                ans.pop_back();
                
            }
            ans+=i;
        }
        return ans;
    }
};