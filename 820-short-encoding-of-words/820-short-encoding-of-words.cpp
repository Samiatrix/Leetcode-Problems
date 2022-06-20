class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> uni(words.begin(), words.end());
        
        for(int i=0;i<words.size();i++){
            for(int j=1;j<words[i].size();j++){
                uni.erase(words[i].substr(j));
            }
        }
        int s = 0;
        for(auto i:uni){
            s += i.size()+1;
        }
        return s;
    }
};