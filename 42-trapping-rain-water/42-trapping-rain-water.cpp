class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0, maxRight = 0, ans =0;
        int l = 0, r = height.size()-1;
        while(l<=r){
            if(height[l]<=height[r]){
                if(maxLeft<=height[l]){
                    maxLeft = height[l];
                }
                else{
                    ans+=(maxLeft-height[l]);
                }
                l++;
            }
            else{
                if(maxRight<=height[r]){
                    maxRight = height[r];
                }
                else{
                    ans += (maxRight-height[r]);
                }
                r--;
            }
        }
        return ans;
    }
};