class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        //to make n&d >0
        bool n1=numerator<0;
        bool d1=denominator<0;
        long n=numerator, d=denominator;
        if(n1) n=-n;
        if(d1) d=-d;
        //before->before point, after->after point
        long before=n/d, after=n%d;
        string res;
        //all before
        if(before==0) res.append("0");
        while(before>0){
            res.push_back((before%10)+'0');
            before/=10;
        }
        if(n1^d1) res.push_back('-');
        reverse(res.begin(),res.end());
        if(after==0) return res;
        // after
        res.push_back('.');
        vector<char> point;
        unordered_map<long,int> hash; //key->after, value->pos
        int count=0,repeat=-1; //used to store the pos of repeat
        while(true){
            after*=10;
            if(hash.find(after)!=hash.end()){
                repeat=hash[after];  //store repeat pos
                break;
            }
            else hash[after]=count;
            count++;
            point.push_back(after/d+'0');
            long i=after%d;
            
            if(i==0) break; //no repeat
            after=i;
        }
        if(repeat==0){
            res.push_back('(');
        }
        for(int i=0;i<point.size();i++){
            res.push_back(point[i]);
            if(i+1==repeat) res.push_back('(');
        }
        if(repeat>=0) res.push_back(')');
        return res;
        
        
    }
};