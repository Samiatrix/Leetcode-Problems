class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = 0;
        while(l<r){
            int curr = (r-l)*min(height[l], height[r]);
            ans = max(ans, curr);
            if(height[l]<height[r]){
                l++;
            }
            else    r--;
        }
        return ans;
    }
};