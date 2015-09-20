class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        stack<int> s;
        if(height.size()<3) return 0;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&height[i]>height[s.top()]){
                int tmp=s.top();
                s.pop();
                if(!s.empty()){
                    int w=i-s.top()-1;
                    int h=min(height[i],height[s.top()])-height[tmp];
                    sum+=w*h;
                }
            }
            s.push(i);
        }
        return sum;
    }
};