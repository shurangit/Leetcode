class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minl=INT_MAX, sum=0,start=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=s){
                minl=min(minl,i-start+1);
                sum-=nums[start];
                start++;
            }
        }
        return minl==INT_MAX? 0:minl;
    }
};