class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)==string::npos) return -1;
        size_t i = haystack.find(needle);
        return int(i);
    }
};