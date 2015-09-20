class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0) return res;
        int wordSize=words[0].size();
        int wordNo=words.size();
        int totalLen=wordNo*wordSize;
        if(s.size()<totalLen) return res;
        unordered_map<string,int> hash;
        for(int i=0;i<wordNo;i++){
            hash[words[i]]++;
        }
        
        for(int i=0;i<=s.size()-totalLen;i++){ //use totalLen because the words need to be continus
            if(check(s,hash,i,wordSize,wordNo)) res.push_back(i);
        }
        return res;
        
        
    }
    
    bool check(string s,unordered_map<string,int>& hash, int start, int wordSize, int wordNo){
        if(s.size()-start+1<wordNo*wordSize) return false;
        unordered_map<string,int> wordF;
        
        for(int i=0;i<wordNo;i++){
            string tmp=s.substr(start+i*wordSize,wordSize);
            if(hash.find(tmp)==hash.end()) return false;
            else wordF[tmp]++;
            if(wordF[tmp]>hash[tmp]) return false;
        }
        return true;
    }
};