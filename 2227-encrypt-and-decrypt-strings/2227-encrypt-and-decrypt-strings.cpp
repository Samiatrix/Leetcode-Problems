class Encrypter {
public:
    unordered_map<char, string> keyToValue;
    unordered_map<string, int> mp;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            keyToValue[keys[i]] = values[i];
        }
        
        for(auto i:dictionary){
            string encrypted = encrypt(i);
            mp[encrypted]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(auto ch:word1){
            ans+=(keyToValue[ch]);
        }
        return ans;
    }
    int decrypt(string word2) {
        return mp[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */