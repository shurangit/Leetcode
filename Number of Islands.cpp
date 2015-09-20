class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        int total;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    total++;
                    GridIsVisited(i,j,grid);
                }
            }
        }
        return total;
    }
    //visit a island and make this visited
    void GridIsVisited(int col,int row,vector<vector<char>>& grid){
        if(grid[col][row]=='0'||grid[col][row]=='v') return;
        grid[col][row]='v';
        if(col!=0) GridIsVisited(col-1,row,grid);
        if(col!=grid.size()-1) GridIsVisited(col+1,row,grid);
        if(row!=0) GridIsVisited(col,row-1,grid);
        if(row!=grid[0].size()-1) GridIsVisited(col,row+1,grid);
        return;
    }
};