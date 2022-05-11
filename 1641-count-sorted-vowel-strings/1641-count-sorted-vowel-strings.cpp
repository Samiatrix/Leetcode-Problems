class Solution {
public:
    int countVowelStrings(int n) {
        n+=4;
        long long ans = n*(n-1)*(n-2)*(n-3)/24;
        return ans;
    }
};