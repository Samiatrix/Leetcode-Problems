struct Node{
    Node* links[26];
    bool end;
    
    void put(char ch, Node* curr){
        this->links[ch-'a'] = curr;
        
    }
    bool isEnd(){
        return this->end;
    }
    Node* get(char ch){
        return this->links[ch-'a'];
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
            if(node->get(word[i]) == NULL){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->end = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->get(word[i]) == NULL){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->get(prefix[i]) == NULL){
                return false;
            }
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