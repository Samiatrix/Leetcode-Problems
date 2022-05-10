class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        for(int i = 0, j = 0;i < firstList.size() && j < secondList.size();firstList[i][1] < secondList[j][1] ? i++ : j++){
            int ma = max(firstList[i][0], secondList[j][0]);
            int mi = min(firstList[i][1], secondList[j][1]);
            if(ma<=mi)  ans.push_back({ma, mi});
        }
        return ans;
    }
};