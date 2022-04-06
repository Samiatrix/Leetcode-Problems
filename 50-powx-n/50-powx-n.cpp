class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1;
        // if(n == 1)  return x;
        if(n<0){
            return 1.0/x * myPow(1/x, -(n+1));
        }
        return n&1 ? x*myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};