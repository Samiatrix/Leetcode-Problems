struct Node{
    Node* links[26];
    bool end = false;
    
    bool isExists(char ch){
        return (links[ch-'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!(node->isExists(word[i]))){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isExists(word[i])){
                node = node->get(word[i]);
            }
            else{
                return false;
            }
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->isExists(prefix[i]))    return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */