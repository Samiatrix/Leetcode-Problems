class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> newNums;
        for(auto i:nums)    newNums.push_back(to_string(i));
        sort(newNums.begin(), newNums.end(), [](string a, string b){
            string s = a+b;
            string t = b+a;
            return s>t;
        });
        string ans = "";
        for(auto i:newNums) ans+=i;
        return ans[0] == '0' ? "0" : ans;
    }
};