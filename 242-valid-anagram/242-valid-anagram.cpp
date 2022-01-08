class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())    return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int ind = 0;
        while(ind<s.size()){
            if(s[ind]!=t[ind])  return false;
            ind++;
        }
        return true;
        
    }
};