class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> st;
        vector<int> pre;
        vector<int> suff(s.size());
        for(auto i:s){
            st.insert(i);
            pre.push_back(st.size());
        }
        st.clear();
        
        for(int i=s.size()-1;i>=0;i--){
            st.insert(s[i]);
            suff[i] = st.size();
        }
        int ans = 0;
        // int sl = 0, sr = mp.size();
        for(int i=0;i<s.size()-1;i++){
            ans += pre[i] == suff[i+1];
            // char ch = s[i];
            // if(mp[ch] == 1){
            //     mp.erase(ch);
            //     mpp[ch]++;
            // }
            // else{
            //     mp[ch]--;
            //     mpp[ch]++;
            // }
            // ans += mp.size() == mpp.size();
        }
        return ans;
    }
};