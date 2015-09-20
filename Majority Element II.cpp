class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n1=0,n2=0;
        int a,b;
        int n=nums.size();
        for(auto n:nums){
            
            if(n1==0||n==a) {
                
                n1++;
                a=n;
            }
            else if(n2==0||n==b){
                b=n;
                n2++;
            }
            else{
                n1--;
                n2--;
            }
        }
        n1=n2=0;
        for(auto n:nums){
            if(n==a) n1++;
            else if(n==b) n2++;
        }
        if(n1>n/3) res.push_back(a);
        if(n2>n/3) res.push_back(b);
        
        return res;
    }
};