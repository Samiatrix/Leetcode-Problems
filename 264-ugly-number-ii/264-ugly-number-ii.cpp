class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        vector<int> ugly(n);
        int multipleOf2 = 0, multipleOf3 = 0, multipleOf5 = 0;
        ugly[0] = 1;
        for(int i=1;i<n;i++){
            ugly[i] = min({ ugly[multipleOf2] * 2, ugly[multipleOf3] * 3, ugly[multipleOf5] * 5 });
            if(ugly[i] == ugly[multipleOf2] * 2)    multipleOf2++;
            if(ugly[i] == ugly[multipleOf3] * 3)    multipleOf3++;
            if(ugly[i] == ugly[multipleOf5] * 5)    multipleOf5++;
        }
        return ugly[n-1];
    }
};