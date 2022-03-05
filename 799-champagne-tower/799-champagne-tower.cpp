class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tow;
        tow.push_back({(double)(poured)});
        for(int i=0;i<=query_row;i++){
            vector<double> t(i+2);
            for(int j=0;j<=i;j++){
                double d = (tow[i][j]-1.0)/2.0;
                if(d>0){
                    t[j] += d;
                    t[j+1] += d;
                }
            }
            tow.push_back(t);
        }
        return min(1.00, tow[query_row][query_glass]);
    }
};