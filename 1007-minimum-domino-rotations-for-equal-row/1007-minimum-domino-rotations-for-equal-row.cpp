class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> top(7), bottom(7), same(7);
        for(int i=0;i<tops.size();i++){
            top[tops[i]]++;
            bottom[bottoms[i]]++;
            if(tops[i] == bottoms[i])   same[tops[i]]++;
        }
        int ans = 0;
        for(int i=0;i<7;i++){
            if(top[i]+bottom[i]-same[i] == tops.size()){
                return (tops.size() - max(top[i], bottom[i]));
            }
        }
        return -1;
    }
};