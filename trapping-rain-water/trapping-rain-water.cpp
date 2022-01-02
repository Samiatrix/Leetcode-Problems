class Solution {
public:
    int trap(vector<int>& height) {
        // int pre = 0;
        // vector<int> left(height.size());
        // for(int i=0;i<height.size();i++){
        //     if(pre<height[i]){
        //         pre = height[i];
        //     }
        //     left[i] = pre;
        // }
        // vector<int> right(height.size());
        // pre = 0;
        // for(int i=height.size()-1;i>=0;i--){
        //     if(pre<height[i]){
        //         pre = height[i];
        //     }
        //     right[i] = pre;
        // }
        int ans = 0;
        // for(int i=0;i<height.size();i++){
        //     ans += (min(left[i], right[i]))-height[i];
        // }
        int l = 0, r = height.size()-1;
        int left = 0, right = 0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=left) left = height[l];
                else{
                    ans+=(left-height[l]);
                }
                l++;
            }
            else{
                if(height[r]>=right)    right = height[r];
                else    ans+=(right-height[r]);
                r--;
            }
        }
        return ans;
    }
};