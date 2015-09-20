class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0;
        int start=-1, mark=-1;
        while(i<s.size()){
            // j='?' or p[j]=s[i]
           if(j<p.size()&&(p[j]=='?')||s[i]==p[j]){
               i++;
               j++;
           }
           //if p[j]='*', 1）如果连着*，则start是最后一个*的位置，mark是记录i的位置
           
           else if(j<p.size()&&p[j]=='*'){
               start=j;
               j++;
               mark=i;
           }
           //如果存在*，则将*之后一位与s比较，因为*可以代表多位，则i一直后移直到符合前面条件
           
           else if(start!=-1){
               j=start+1;
               i=++mark;
           }
           else return false; //没匹配上
        }
        
        //处理p后面多余的*
        while(j<p.size()&&p[j]=='*') j++;
        
        return (j==p.size())? true:false;
    }
};