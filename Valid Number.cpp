class Solution {
public:
    bool isNumber(string s) {
        if(s.size()==0) return false;
        //ignore head/tail space
        while (s[0] == ' ') s.erase(s.begin());   //get rid of white space from beginning
        while (s[s.size()-1] == ' ') s.erase(s.end()-1); 
        
        int len=s.size();
        bool num=false, dot=false, ex=false;
        for(int i=0;i<len;i++){
            char c=s[i];
            if(c=='e'){
                if(!num||ex) return false; //ǰ��û�����֣���ǰ���Ѵ���e
                ex=true;
                num=false; //e������Ҫnumber
            }
            else if (c>='0'&&c<='9'){
                num=true;
            }
            else if(c=='.'){
                if(ex||dot) return false; //e���治����С�� �� ֻ����һ����
                dot=true;
            }
            else if(c=='+'||c=='-'){
                if(i!=0&&s[i-1]!='e') return false; //ֻ�е�һλ����e����һλ�����Ƿ���
            }
            else{
                return false;
            }
        }
        return num;
    }
};