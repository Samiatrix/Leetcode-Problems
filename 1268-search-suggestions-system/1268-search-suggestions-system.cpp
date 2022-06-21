class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string curr = "";
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            curr += searchWord[i];
            vector<string> t;
            auto it = lower_bound(products.begin(), products.end(), curr);
            for(int j=0 ; j<3 && it+j != products.end() ; j++){
                string s = *(it+j);
                if(s.find(curr))    break;
                t.push_back(s);
            }
            ans.push_back(t);
        }
        return ans;
    }
};