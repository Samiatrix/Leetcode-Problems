struct Trie{ 
    bool end = false;
    unordered_map<char, Trie*> children;

    bool isEnd(){
        return this->end;
    }

    void put(char ch, Trie* node){
        this->children[ch] = node;
    }

    Trie* get(char ch){
        return children[ch];
    }
    
    bool isExist(char ch){
        return children.count(ch);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    vector<pair<Trie*, int>> leaves;
    void insert(string s){
        Trie* node = root;
        for(int i=s.size()-1;i>=0;i--){
            if(!node->isExist(s[i])){
                node->put(s[i], new Trie());
            }
            node = node->get(s[i]);
        }
        node->end = true;
        leaves.push_back({node, s.size()+1});
    }
    int minimumLengthEncoding(vector<string>& words) {
        for(auto word : unordered_set<string> (words.begin(), words.end())){
            insert(word);
        }
        int ans = 0;
        for(auto curr : leaves){
            if(curr.first->children.size() == 0)    ans+=curr.second;
        }
        return ans;
        
        
//         unordered_set<string> uni(words.begin(), words.end());
        
//         for(int i=0;i<words.size();i++){
//             for(int j=1;j<words[i].size();j++){
//                 uni.erase(words[i].substr(j));
//             }
//         }
//         int s = 0;
//         for(auto i:uni){
//             s += i.size()+1;
//         }
//         return s;
    }
};