class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0,index=0,cursum=0;
        for(int i=0;i<gas.size();i++){
            sum+=gas[i]-cost[i];
            cursum+=gas[i]-cost[i];
            if(cursum<0) {
                index=i+1;
                cursum=0;
            }
        }
        if(sum<0) return -1;
        else return index;
    }
};