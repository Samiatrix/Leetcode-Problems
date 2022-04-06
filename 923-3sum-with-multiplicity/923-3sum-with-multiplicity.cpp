class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int count = 0;
        sort(begin(A), end(A));
        for(int i=0;i<A.size()-2;i++){
            int t = target - A[i];
            int j = i+1, k = A.size()-1;
            while(j<k){
                int s = A[j]+A[k];
                if(s == t){
                    if(A[j]!=A[k]){
                        int l = 1, r = 1;
                        while(j+1<k && A[j+1] == A[j]){
                            l++;
                            j++;
                        }
                        while(j<k-1 && A[k-1] == A[k]){
                            r++;
                            k--;
                        }
                        count = (count + l*r)%int(1e9+7);
                        j++;
                        k--;
                    }
                    else{
                        count = (count+(k-j+1)*(k-j)/2)%int(1e9+7);
                        break;
                    }
                }
                else if(s>t){
                    k--;
                }
                else if(s<t){
                    j++;
                }
            }
        }
        return count%int(1e9+7);
    }
};