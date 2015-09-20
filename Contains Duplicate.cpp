class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hash;
        if(nums.size()==0||nums.size()==1) return false;
        hash.insert(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()) return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};