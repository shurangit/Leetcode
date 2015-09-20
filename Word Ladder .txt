class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<pair<string,int>> que; //value->length
        que.push(make_pair(beginWord,1));
        while(!que.empty()){
            string s=que.front().first;
            int len=que.front().second;
            if(s==endWord) return len;
            que.pop();
            vector<string> adj=neighbors(s,wordDict);
            for(int i=0;i<adj.size();i++){
                que.push(make_pair(adj[i],len+1));
            }
        }
        return 0;
        
    }
    
    vector<string> neighbors(string s, unordered_set<string>& wordDict){
        vector<string> adj;
        for(int i=0;i<s.size();i++){
            char tmp=s[i];
            for(char j='a';j<='z';j++){
                if(tmp==j) continue;
                s[i]=j;
                if(wordDict.count(s)){
                    adj.push_back(s);
                    wordDict.erase(s);
                }
            }
            s[i]=tmp;
        }
        return adj;
    }
};