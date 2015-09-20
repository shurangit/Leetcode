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
class WordDictionary {
public:
    WordDictionary(){
        root=new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string s) {
        TrieNode* node=root;
        for(int i=0;i<s.size();i++ ){
            if(!node->children[s[i]-'a']){
                node->children[s[i]-'a']=new TrieNode();
            }
            node=node->children[s[i]-'a'];
        }
        node->isEnd=true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        searchWord(word,root,0);
    }
private:
    TrieNode* root;
    bool searchWord(string &word, TrieNode* node, int start){
        if(start>=word.size()){
            return node->isEnd; //whether the end node is the word's end
        }
        if(word[start]=='.'){ //'.' -> any letter
            for(int i=0;i<26;i++){
                if(node->children[i]&&searchWord(word,node->children[i],start+1)) return true;
                
            }
            return false;
        }
        return node->children[word[start]-'a']&&searchWord(word,node->children[word[start]-'a'],start+1);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");