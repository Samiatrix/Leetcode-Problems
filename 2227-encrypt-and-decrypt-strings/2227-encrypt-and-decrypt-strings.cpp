struct Trie{
    Trie* links[26];
    bool end = false;
    
    void put(char ch, Trie* node){
        links[ch-'a'] = node;
    }
    
    Trie* get(char ch){
        return links[ch-'a'];
    }
    
    bool isEnd(){
        return end;
    }
    
    // void insert(string word){
    //     for
    // }
};
class Encrypter {
public:
    unordered_map<char, string> keyToValue;
    unordered_map<string, vector<char>> valuesToKeys;
    Trie* root = new Trie();
    
    void insert(Trie* root, string& word){
        Trie* curr = root;
        for(auto c:word){
            if(!curr->get(c))   curr->put(c, new Trie());
            curr = curr->get(c);
        }
        curr->end = true;
    }
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            keyToValue[keys[i]] = values[i];
            valuesToKeys[values[i]].push_back(keys[i]);
        }
        for(auto i:dictionary){
            insert(root, i);
        }
        // for(auto i:dictionary){
        //     string encrypted = encrypt(i);
        //     mp[encrypted]++;
        // }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(auto ch:word1){
            ans+=(keyToValue[ch]);
        }
        return ans;
    }
    int dfs(string& s, Trie* root, int ind){
        if(ind == s.size()) return root->isEnd() == true;
        int ans = 0;
        string t = s.substr(ind, 2);
        for(auto ch:valuesToKeys[t]){
            if(root->get(ch)){
                ans+=dfs(s, root->get(ch), ind+2);
            }
        }
        return ans;
    }
    int decrypt(string word2) {
        return dfs(word2, root, 0);
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */