class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i:A){
            for(int j:B){
                mp[i+j]++;
            }
        }
        for(int i:C){
            for(int j:D){
                if(mp.count(0-(i+j)))   ans+=mp[0-(i+j)];
            }
        }
        
        return ans;
    }
};