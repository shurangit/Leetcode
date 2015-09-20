class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0||matrix[0].size()==0) return res;
        spiral(res,matrix,0,0,matrix.size()-1,matrix[0].size()-1);
        return res;
    }
    
    void spiral(vector<int>& res, vector<vector<int>>& matrix, int start_c, int start_r,int end_c,int end_r){
        if(start_c>end_c||start_r>end_r) return; //stop
        //one element left
        if(start_c==end_c&&start_r==end_r){
           res.push_back(matrix[start_c][start_r]);
           return;
        }
        //one row left
        if(start_c==end_c){
            for(int j=start_r;j<=end_r;j++){
                res.push_back(matrix[start_c][j]);
            }
            return;
        }
        //one column left
        if(start_r==end_r){
            for(int i=start_c;i<=end_c;i++){
                res.push_back(matrix[i][start_r]);
            }
            return;
        }
        //first column
        for(int i=start_r;i<end_r;i++){
            res.push_back(matrix[start_c][i]);
        }
        //right row
        for(int j=start_c;j<end_c;j++){
            res.push_back(matrix[j][end_r]);
        }
        //last column
        for(int i=end_r;i>start_r;i--){
            res.push_back(matrix[end_c][i]);
        }
        //left row
        for(int j=end_c;j>start_c;j--){
            res.push_back(matrix[j][start_r]);
        }
        spiral(res,matrix,start_c+1,start_r+1,end_c-1,end_r-1);
    }
};