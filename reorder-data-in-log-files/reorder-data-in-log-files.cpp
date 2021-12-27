class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> letter;
        vector<pair<string, string>> digits;
        for(auto s:logs){
            string identifier = "";
            string log="";
            bool spaceFound = false;
            for(int i=0;i<s.size();i++){
                if(!spaceFound && s[i] != ' '){
                    identifier+=s[i];
                }
                else if(!spaceFound && s[i] == ' '){
                    spaceFound = true;
                }
                else if(spaceFound){
                    log+=s[i];
                }
            }
            if(isdigit(log[0])){
                digits.push_back({identifier, log});
            }
            else{
                letter.push_back({identifier, log});
            }
        }
        sort(letter.begin(), letter.end(), [](pair<string, string> a, pair<string, string> b){
            return a.second == b.second ? a.first<b.first : a.second<b.second;
        });
        vector<string> ans;
        for(auto p:letter){
            ans.push_back(p.first+" "+p.second);
        }
        for(auto p:digits){
            ans.push_back(p.first+" "+p.second);
        }
        return ans;
    }
};