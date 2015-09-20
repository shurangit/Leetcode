class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start=1, N=nums.size();
        if(N<=1) return N;
        for(int i=1;i<N;i++){
            if(nums[i]!=nums[i-1]) nums[start++]=nums[i];
            
        }
        return start;
    }
};