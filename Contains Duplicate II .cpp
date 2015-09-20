class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])!=hash.end()){
                if(i-hash.find(nums[i])->second<=k) return true;
            }
            hash[nums[i]]=i;
        }
        return false;
    }
};