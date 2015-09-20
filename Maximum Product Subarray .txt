class Solution { 
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res=nums[0],minn=nums[0],maxx=nums[0];
        for(int i=1;i<nums.size();i++){
            int ma=max(nums[i]*maxx,max(nums[i]*minn,nums[i]));
            int mi=min(nums[i]*maxx,min(nums[i]*minn,nums[i]));
            res=max(ma,res);
            maxx=ma;minn=mi;
        }
        return res;
    }
};