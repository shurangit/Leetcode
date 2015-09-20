class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int col=matrix.size(), row=matrix[0].size();
        vector<vector<int>> height(col,vector<int>(row,0));
        //initialize height
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
                if(matrix[i][j]=='1'){
                    height[i][j]=(i==0)? 1:height[i-1][j]+1;
                }
            }
        }
        int res=0;
        for(int i=0;i<col;i++){
            res=max(res,largestRectangleArea(height[i]));
        }
        return res;
        
    }
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