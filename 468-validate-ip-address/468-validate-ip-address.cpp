class Solution {
public:
    string solveIPV4(string s){
        bool good = true;
        vector<string> split;
        string t = "";
        for(auto i:s){
            if(i == '.'){
                split.push_back(t);
                t = "";
            }
            else{
                t+=i;
            }
        }
        split.push_back(t);
        if(split.size()!=4) return "Neither";
        for(auto word:split){
            for(auto i:word){
                if(!isdigit(i))  return "Neither";
            }
            if(word.size()>3)   return "Neither";
            else if(word.size()>1){
                if(word[0] == '0'){
                    good = false;
                    break;
                }
                else{
                    int curr = stoi(word);
                    if(curr<0 || curr>255){
                        good = false;
                        break;
                    }
                }
            }
            else if(word == ""){
                good = false;
                break;
            }
        }
        return good ? "IPv4" : "Neither";
    }
    string solveIPV6(string s){
        bool good = true;
        vector<string> split;
        string t = "";
        for(auto i:s){
            if(i == ':'){
                split.push_back(t);
                t = "";
            }
            else{
                t+=i;
            }
        }
        split.push_back(t);
        if(split.size()!=8) return "Neither";
        for(auto word:split){
            for(auto i:word){
                if(!isdigit(i)){
                    // cout<<i<<endl;
                    char ch = tolower(i);
                    if('a'>ch || ch>'f')    return "Neither";
                }
            }
            if(word.size()<=0 || word.size()>4){
                good = false;
                break;
            }
            else if(word == ""){
                good = false;
                break;
            }
            
        }
        return good ? "IPv6" : "Neither";
    }
    string validIPAddress(string queryIP) {
        if(queryIP == "")   return "Neither";
        if((queryIP.find(":")!=string::npos) && (queryIP.find(".")!=string::npos))  return "Neither";
        else if((queryIP.find(":")!=string::npos) && (queryIP.find(".")==string::npos)){
            return solveIPV6(queryIP);
        }
        else if((queryIP.find(":")==string::npos) && (queryIP.find(".")!=string::npos)){
            return solveIPV4(queryIP);
        }
        return "";
    }
};