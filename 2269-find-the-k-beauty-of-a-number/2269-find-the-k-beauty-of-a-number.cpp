class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int ans = 0;
        string curr = "";
        for(int i=0, j=0;j<s.size();j++){
            curr += s[j];
            if(j-i+1 == k){
                int n = stoi(curr);
                if(n!=0 && num%n == 0)  ans++;
                curr = curr.substr(1);
                i++;
            }
        }
        return ans;
    }
};