class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return;
        int m=matrix.size(), n=matrix[0].size();
        
        bool firstrow=false,firstcol=false;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0) {firstcol=true;break;}
        }
        for(int i=0;i<n;i++){
            if(matrix[0][i]==0) {firstrow=true;break;}
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[i][0]==0) set(matrix,i,true);
        }
        for(int i=1;i<n;i++){
            if(matrix[0][i]==0) set(matrix,i,false);
        }
        if(firstrow) set(matrix,0,true);
        if(firstcol) set(matrix,0,false);
        
        
    }
    void set(vector<vector<int>>& matrix,int index, bool row){
        if(matrix.empty()||matrix[0].empty()||index<0) return;
        int m=matrix.size(), n=matrix[0].size();
        if((row&&index>=m)||(!row&&index>=n)) return;
        if(row){
            for(int i=0;i<n;i++){
                matrix[index][i]=0;
            }
        }
        else{
            for(int i=0;i<m;i++){
                matrix[i][index]=0;
            }
        }
        
    }
};