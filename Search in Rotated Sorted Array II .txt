class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.empty()) return false;
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[end]){
                end--;
            }else if(nums[mid]<nums[end]){
                if(nums[mid]<target&&nums[end]>=target) start=mid+1;
                else end=mid-1;
            }
            else{
                if(nums[start]<=target&&nums[mid]>target) end=mid-1;
                else start=mid+1;
            }
        }
        return false;
    }
};