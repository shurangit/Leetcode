class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int sum=0;
        stack<int> s;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&height[i]<height[s.top()]){
                int tmp=s.top();
                int h=height[tmp];
                s.pop();
                int l=(s.empty())? i:i-s.top()-1;
                sum=max(sum,l*h);
            }
            s.push(i);
        }
        return sum;
    }
};