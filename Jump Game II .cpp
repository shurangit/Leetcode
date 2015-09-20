class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0, i=0,cur=0; //cur->max distance nums[0...i] can reach 
        //not reach end
        while(cur<nums.size()-1){
            int tmp=cur;
            for(;i<=tmp;i++){
                cur=max(cur,nums[i]+i);
            }
            res++;
            //cannot reach end
            if(cur==tmp) return -1;
        }
        return res;
    }
};