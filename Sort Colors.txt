class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            int left=0, right=nums.size()-1;
            int pivot=nums[i];
            for(int j=0;j<nums.size();j++){
                if(pivot>nums[j]){
                    swap(nums[left],nums[j]);
                    left++;
                }
                else if(pivot<nums[j]){
                    swap(nums[j],nums[right]);
                    right--;
                }
                if(left==right||right<=j){
                    break;
                }
            }
            
        }
    }
};