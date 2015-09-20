class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size(), i, start ;
            vector<string> res;

            for(i=1, start=0;i<=len;++i)
            {
                if(i==len || (nums[i-1] + 1)!=nums[i])
                { // the current range is finished or it reaches the end of vector, write back
                    res.push_back(((i-1) ==start)? to_string(nums[start]): (to_string(nums[start])+"->"+to_string(nums[i-1])));
                    start = i;
                }
            }
            return res;
        }
};