class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = -1;
        right[n-1] = n;
        for(int i=1;i<n;i++){
            int pre = i-1;
            while(pre>=0 && heights[pre]>=heights[i])   pre = left[pre];
            left[i] = pre;
        }
        for(int i=n-2;i>=0;i--){
            int pre = i+1;
            while(pre<n && heights[pre]>=heights[i])    pre = right[pre];
            right[i] = pre;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int temp = heights[i]*(right[i]-left[i]-1);
            ans = max(ans, temp);
        }
        return ans;
        
    }
};