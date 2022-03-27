class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int start = (intLength%2 == 0) ? (intLength/2-1) : (intLength/2);
        int end = (intLength%2 == 0) ? (intLength/2) : (intLength/2 + 1);
        long long ind = pow(10, start);
        long long last = pow(10, end)-1;
        vector<string> t;
        // int m = *max_element(queries.begin(), queries.end());
        // for(int i=0;i<=m;i++){
        //     string s = to_string(ind);
        //     if(intLength & 1){
        //         string ss = s.substr(0, s.size()-1);
        //         reverse(ss.begin(), ss.end());
        //         s+=(ss);
        //         if(s.size() == intLength)   t.push_back(s);
        //     }
        //     else{
        //         string ss = s;
        //         reverse(ss.begin(), ss.end());
        //         s+=(ss);
        //         if(s.size() == intLength)   t.push_back(s);
        //     }
        //     ind++;
        // }
        // // sort(t.begin(), t.end());
        vector<long long> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i] <= (last-ind+1)){
                int firstHalf = ind+(queries[i]-1);

                string s = to_string(firstHalf);
                if(intLength & 1){
                    string ss = s.substr(0, s.size()-1);
                    reverse(ss.begin(), ss.end());
                    s+=(ss);
                    if(s.size() == intLength)   ans.push_back(stol(s));
                }
                else{
                    string ss = s;
                    reverse(ss.begin(), ss.end());
                    s+=(ss);
                    if(s.size() == intLength)   ans.push_back(stol(s));
                }
            }
            else{
                ans.push_back(-1);
            }
            // ind++;
            // ans.push_back(t.size()>=(queries[i]-1) ? stol(t[queries[i]-1]) : -1);
        }
        return ans;
        
        
        
    }
};