class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int top = 0;
        unordered_map<int, int> tm;
        int gr = -1;
        int maxi = 0;
        for(auto &i:tops){
            tm[i]++;
            if(maxi<tm[i]){
                maxi = tm[i];
                gr = i;
            }
        }
        maxi = 0;
        int gb = -1;
        unordered_map<int, int> bm;
        for(auto &i:bottoms){
            bm[i]++;
            if(maxi<tm[i]){
                maxi = tm[i];
                gb = i;
            }
        }
        
        int curr = 0;
        int ans = INT_MAX;
        
        for(int i=0;i<tops.size();i++){
            if(gr != tops[i]){
                if(bottoms[i] == gr)    curr++;
                else{
                    curr = INT_MAX;
                    break;
                }
            }
        }
        ans = min(ans, curr);
        curr = 0;
        for(int i=0;i<bottoms.size();i++){
            if(gb != bottoms[i]){
                if(tops[i] == gb)    curr++;
                else{
                    curr = INT_MAX;
                    break;
                }
            }
        }
        ans = min(ans, curr);
        
        return ans == INT_MAX ? -1 : ans;
        
        
    }
};