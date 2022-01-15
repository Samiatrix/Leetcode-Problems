class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)  return 0;
        if(haystack.size() == 0)    return -1;
        for(int i=0;i<haystack.size();i++){
            if(i+needle.size()>haystack.size())    break;
            for(int j=0, k=i;j<needle.size();j++){
                if(haystack[k+j] != needle[j])    break;
                if(j == needle.size()-1)  return i;
            }
        }
        return -1;
    }
};