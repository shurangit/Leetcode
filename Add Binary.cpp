class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i=a.size(), j=b.size(),cur=0;
        while(i||j||cur){
            int aa=i?a[(i--)-1]-'0':0;
            int bb=j?b[(j--)-1]-'0':0;
            cur+=aa+bb;
            res=char(cur%2+'0')+res;
            cur=cur/2;
        }
        return res;
    }
};