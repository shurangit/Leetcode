class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return;
        //find nums[i-1]<nums[i],length=i
        int length=nums.size()-1;
        while(length>0){
            if(nums[length]>nums[length-1]) break;
            length--;
        }
        //if the max, reverse all nums
        if(length==0) reverse(nums.begin(),nums.end());
        //if length!=0,find nums[j]>num[length-1] from length to size-1
        else{
            int i=nums.size()-1;
            for(;i>=length;i--){
                if(nums[i]>nums[length-1]) {
                    
                    break;
                }
            }
            swap(nums[i],nums[length-1]);
            sort(nums.begin()+length,nums.end());
        }
        
    }
};