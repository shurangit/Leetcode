class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> hash;
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i])==hash.end()) {
                hash.insert(pair<int,int>(nums[i],0));
            }
            else{
                hash[nums[i]]++;
            }
        }
        map<int,int>::iterator iter;
        for(iter=hash.begin();iter!=hash.end();iter++){
            if(iter->second>=size/2) return iter->first;
        }
    }
};