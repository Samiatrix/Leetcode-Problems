class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int principle = 0, hold = -1*prices[0];
        for(int i=1;i<prices.size();i++){
            principle = max(principle, hold + prices[i]-fee);
            hold = max(hold, principle-prices[i]);
        }
        return principle;
    }
};