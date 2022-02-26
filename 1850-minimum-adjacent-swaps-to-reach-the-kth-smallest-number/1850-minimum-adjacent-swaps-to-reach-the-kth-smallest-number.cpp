class Solution {
public:
    int getMinSwaps(string num, int k) {
        string org = num;
        while(k--){
            next_permutation(num.begin(), num.end());
        }
        int ans = 0;
        int i=0, j=0;
        while(i<org.size()){
            j = i;
            while(org[i]!=num[j])   j++;
            
            while(i<j){
                swap(num[j-1], num[j]);
                j--;
                ans++;
            }
            i++;
        }
        return ans;
    }
};