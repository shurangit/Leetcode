class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> hash;
        //store all members in hash
        for(int i=0;i<nums.size();i++){
            hash.insert(nums[i]);
        }
        //find 
        int maxx=1;
        for(int i=0;i<nums.size();i++){
            if(hash.empty()) break;
            int len=0,cur=nums[i];
            while(hash.count(cur)){
                hash.erase(cur);
                len++;
                cur++;
            }
            cur=nums[i]-1;
            while(hash.count(cur)){
                hash.erase(cur);
                len++;
                cur--;
            }
            maxx=max(maxx,len);
        }
        
        return maxx;
    }
};