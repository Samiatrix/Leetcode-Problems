class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        for(auto i:t){
            freq[i]++;
        }
        int start = 0, end = 0, count = t.size(), mins = 0, minl = INT_MAX;
        while(end<s.size()){
            if(freq[s[end]]>0){
                count--;                
            }
            freq[s[end]]--;
            end++;
            
            while(count == 0){
                if(end - start < minl){
                    mins = start;
                    minl = end - start;
                }
                freq[s[start]]++;
                // When char exists in t, increase counter.
                if (freq[s[start]] > 0)
                    count++;
                start++;
            }            
        }
        if(minl == INT_MAX) return "";
        else    return s.substr(mins, minl);

    }
};