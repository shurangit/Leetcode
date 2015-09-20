class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l=0, r=nums.size()-1;
        while(l<=r){
            if(l==r) return nums[l];
            int mid=(l+r)/2;
            //remove duplicates
            while(l<mid&&nums[l]==nums[mid]) l++;
            while(r>mid&&nums[r]==nums[mid]) r--;
            
            if(nums[mid]<nums[r]) r=mid;
            if(nums[mid]>nums[r]) l=mid+1;
        }
    }
};