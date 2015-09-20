class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int c=grid[0].size(), r=grid.size();
        vector<vector<int>> store(r,vector<int>(c));
        store[0][0]=grid[0][0];
        for(int i=1;i<r;i++){
            store[i][0]=store[i-1][0]+grid[i][0];
        }
        for(int j=1;j<c;j++){
            store[0][j]=store[0][j-1]+grid[0][j];
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                store[i][j]=min(store[i-1][j],store[i][j-1])+grid[i][j];
            }
        }
        return store[r-1][c-1];
    }
};