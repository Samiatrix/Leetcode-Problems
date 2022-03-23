class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while(X<Y){
            ans++;
            if(Y%2==0){
                Y/=2;
            }
            else{
                Y+=1;
            }
        }
        return ans+X-Y;
    }
};