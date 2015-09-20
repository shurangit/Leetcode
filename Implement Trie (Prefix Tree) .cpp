class TrieNode {
public:
        bool isEnd; //whether a word
        TrieNode *children[26];
    // Initialize your data structure here.
    TrieNode() {
        
        //construct func
            isEnd=false;
            for(int i=0;i<26;i++)
                children[i]=NULL;
            
        
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node=root;
        for(int i=0;i<s.size();i++ ){
            if(!node->children[s[i]-'a']){
                node->children[s[i]-'a']=new TrieNode();
            }
            node=node->children[s[i]-'a'];
        }
        node->isEnd=true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++){
            if(node){
                node=node->children[word[i]-'a'];
            }else break;
        }
        if(!node) return false;
        else return node->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node=root;
        for(int i=0;i<prefix.size();i++){
            if(node){
                node=node->children[prefix[i]-'a'];
            }else break;
        }
        if(!node) return false;
        else return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");