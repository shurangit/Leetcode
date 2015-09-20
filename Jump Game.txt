class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return false;
        int remain=nums[0];
        for(int i=1;i<nums.size();i++){
            if(remain<=0) return false;
            else{
                remain=max(--remain,nums[i]);
            }
        }
        return true;
    }
};