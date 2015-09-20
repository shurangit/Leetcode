class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int n=nums.size();
        int p2=nums[0],p1=max(nums[0],nums[1]),p=p1;
        for(int i=2;i<n-1;i++){
            p=max(p2+nums[i],p1);
            p2=p1;
            p1=p;
        }
        int b2=nums[n-1],b1=max(nums[n-1],nums[n-2]),b=b1;
        for(int j=n-3;j>0;j--){
            b=max(b2+nums[j],b1);
            b2=b1;
            b1=b;
        }
        return max(p,b);
    }
};