class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,N=nums.size();
        if(N==0) return N;
        while(i<N){
            if(nums[i]==val) nums[i]=nums[--N];
            else{
                i++;
            }
        }
        return N;
    }
};