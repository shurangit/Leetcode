class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size=nums.size();
        if(size<3) return size;
        int end=1; //end is the last element of repeats 
        for(int i=2;i<size;i++){
            if(nums[i]!=nums[end-1]) {//end is the last
                nums[++end]=nums[i];
            }
        }
        return end+1;
    }
};