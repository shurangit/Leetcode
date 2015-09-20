class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        if(strs.size()==0) return "";
        if(strs.size()==1) return strs[0];
        int tmp=strs[0].length(),l=0;
        for(int i=1;i<strs.size();i++){
            int l=0;
            int size=(tmp>strs[i].size())? strs[i].size():tmp;
            for(l=0;l<size;l++){
                if(strs[i].at(l)!=strs[0].at(l)) break;
            }
            if(l==0) return "";
            tmp=l;
        }
        return strs[0].substr(0,tmp);
    
    }
};