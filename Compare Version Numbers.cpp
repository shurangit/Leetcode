class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1=number(version1);
        vector<int> v2=number(version2);
        int len=min(v1.size(),v2.size());
        for(int i=0;i<len;i++){
            if(v1[i]>v2[i]) return 1;
            else if(v2[i]>v1[i]) return -1;
                
            
        }
        if(v1.size()>v2.size()) return 1;
        if(v2.size()>v1.size()) return -1;
        return 0;
    }
    vector<int> number(string a){
        vector<int> res;
        if(a.length()==0) return res;
        int tmp=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='.') {
                res.push_back(tmp);
                tmp=0;
            }
            else{
                tmp=tmp*10+a[i]-'0';
                
            }
        }
        res.push_back(tmp);
        vector<int>::iterator Iter=res.end()-1;
        while(*Iter==0){
            res.erase(Iter);
            Iter=res.end()-1;
        }
        return res;
    }
};