class Solution {
public:
    double speed(vector<int>& dist, int h){
        double ans = 0;
        for(int i=0;i<dist.size();i++){
            double t = (dist[i]*1.0)/h;
            t = i!=dist.size()-1 ? ceil(t) : t;
            ans+=t;
        }
        return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e8;
        int ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            double sp = speed(dist, m);
            if(sp <= hour){
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};