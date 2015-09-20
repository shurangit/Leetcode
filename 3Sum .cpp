class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3) return ret;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            for(int j=i+1;j<nums.size()-1;j++){
                if((nums[i]+nums[j])>0) break;
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        std::sort(tmp.begin(),tmp.end());
                        ret.push_back(tmp);
                    }
                    else if(nums[i]+nums[j]+nums[k]>0) break;
                    while(k<nums.size()-1 && nums[k+1]==nums[k]) k++;
                }
                while(j<nums.size()-2 && nums[j+1]==nums[j]) j++;
            }
            while(i<nums.size()-3 && nums[i+1]==nums[i]) i++;
        }
        return ret;
    }
};