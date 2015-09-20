class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return -1;
        int left=0, right=nums.size()-1;
        if(right==0) return nums[0];
        
        while(left<right){
            if(nums[left]<nums[right]) return nums[left];
            int mid=(left+right)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return nums[left];
    }
};