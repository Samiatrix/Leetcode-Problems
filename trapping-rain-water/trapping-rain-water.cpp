class Solution {
public:
    int trap(vector<int>& height) {
        int pre = 0;
        // vector<int> rain(INT_MAX);
        vector<int> left(height.size());
        for(int i=0;i<height.size();i++){
            if(pre<height[i]){
                pre = height[i];
            }
            left[i] = pre;
        }
        vector<int> right(height.size());
        pre = 0;
        for(int i=height.size()-1;i>=0;i--){
            if(pre<height[i]){
                pre = height[i];
            }
            right[i] = pre;
        }
        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans += (min(left[i], right[i]))-height[i];
        }
        // for(auto i:height)  cout<<i<<" ";
        // cout<<endl;
        // for(auto i:left)    cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right)    cout<<i<<" ";
        // cout<<endl;
        return ans;
    }
};