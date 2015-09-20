class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> res_v(num1.size()+num2.size(),0);
        string res="";
        for(int i=num2.size()-1;i>=0;i--){
            int carry=0;
            for(int j=num1.size()-1;j>=0;j--){
                int mul=(num1[j]-'0')*(num2[i]-'0')+carry+res_v[i+j+1];
                res_v[i+j+1]=mul%10;
                carry=mul/10;
            }
            if(carry>0) res_v[i]=carry;
        }
        //delete all 0 from start;
        int k;
        for(k=0;k<(num1.size()+num2.size());k++){
            if(res_v[k]!=0) break;
             
        }
        //vector->string
        for(int l=k;l<(num1.size()+num2.size());l++){
            res+=res_v[l]+'0';
        }
        //if res="0"
        if(res.empty()) res+='0';
        return res;
        
    }
};