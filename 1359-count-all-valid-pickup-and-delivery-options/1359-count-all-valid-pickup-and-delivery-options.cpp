class Solution {
public:
    long long result[10000000] = {0};
    long long mod = 1e9+7;
    int countOrders(int n) {
        long ans = 1;
        for(int i=1;i<=n;i++){
            ans = (ans*i)%mod;
        }
        for(int i=1;i<=(2*n-1);i+=2){
            ans = (ans*i)%mod;
        }
        return ans;
    }
};