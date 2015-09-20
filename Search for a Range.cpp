class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        if(nums.empty()) return res;
        int start=0, end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                int i=mid, j=mid;
                while(nums[i]==target&&i<=end) i++;
                while(nums[j]==target&&j>=start) j--;
                res[0]=(j+1);
                res[1]=(i-1);
                break;
            }
            else if(nums[mid]<target) start=mid+1;
            else end=mid-1;
        }
        return res;
        
    }
};