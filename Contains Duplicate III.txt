class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(!k||t<0||nums.size()<2) return false;
        set<int> store;
        for(int i=0;i<nums.size();i++){
            if(i>k) store.erase(nums[i-k-1]);
            set<int>::iterator iter=store.lower_bound(nums[i]-t);
            if(iter!=store.end()&&abs(nums[i]-*iter)<=t) return true;
            store.insert(nums[i]);
        }
        return false;
    }
};