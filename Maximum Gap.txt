class Solution {
public://use bucket sort
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int maxx=nums[0], minn=nums[0];
        //find range
        for(int i=1;i<nums.size();i++){
            maxx=max(maxx,nums[i]);
            minn=min(minn,nums[i]);
        }
        int len=(maxx-minn)/nums.size()+1;//ceil->向上取整
        int bucketNo=(maxx-minn)/len+1;
        //initialize bucket bucket[i][0] ith->min,,bucket[i][1] ith->max
        vector<vector<int>> bucket(bucketNo);
        for(int i=0;i<nums.size();i++){
            int index=(nums[i]-minn)/len;
            if(bucket[index].empty()){
                //bucket[i].reserve(2);
                bucket[index].push_back(nums[i]);
                bucket[index].push_back(nums[i]);
            }
            else{
                if(bucket[index][0]>nums[i]) bucket[index][0]=nums[i];
                if(bucket[index][1]<nums[i]) bucket[index][1]=nums[i];
            }
        }
          
          //find gap
          int gap=0,prev=0;
          for(int i=1;i<bucket.size();i++){
              if(bucket[i].empty()) continue;
              gap=max(gap,bucket[i][0]-bucket[prev][1]);
              prev=i;
          }
          return gap;
    }
};