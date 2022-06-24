class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int l = q.size();
            while(l--){
                auto curr = q.front();
                q.pop();
                if(curr == endWord) return ans;
                s.erase(curr);
                
                for(int i=0;i<curr.size();i++){
                    char ch = curr[i];
                    for(int k=0;k<26;k++){
                        curr[i] = k+'a';
                        if(s.count(curr))   q.push(curr);
                    }
                    curr[i] = ch;
                }
            }
            ans++;
        }
        return 0;
    }
};