class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 0);
        row[0] = 1;
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>0;j--){
                if(j == i){
                    row[0] = row[j] = 1;
                }
                else{
                    row[j] = row[j-1]+row[j];
                }
            }
        }
        return row;
    }
};