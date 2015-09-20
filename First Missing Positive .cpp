class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        int i=0,n=nums.size();
        //ignore non-positives
        while(i<n&&nums[i]<=0) i++;
        //find 
        for(;i<n;i++){
            //ignore repeats 
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]>res+1) break;
            else res=nums[i];
        }
        return res+1;
    }
};