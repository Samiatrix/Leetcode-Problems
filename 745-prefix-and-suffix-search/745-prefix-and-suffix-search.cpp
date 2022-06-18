class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            string t;
            for(int j=0;j<s.size();j++)
            {
                t+=s[j];
                string u;
                for(int k=s.size()-1;k>=0;k--)
                {
                    u=s[k]+u;
                    mp[t+'*'+u]=i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix+'*'+suffix]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */