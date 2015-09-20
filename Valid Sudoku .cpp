class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size()!=9||board[0].size()!=9) return false;
        //check col
        for(int i=0;i<9;i++){
            vector<bool> store(9,false);
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.') continue;
                int tmp=board[i][j]-'0';
                if(tmp==0||store[tmp-1]) return false;
                store[tmp-1]=true;
            }
        }
        //check row
        for(int j=0;j<9;j++){
            vector<bool> store(9,false);
            for(int i=0;i<9;i++){
                
                if(board[i][j]=='.') continue;
                int tmp=board[i][j]-'0';
                if(tmp==0||store[tmp-1]) return false;
                store[tmp-1]=true;
            }
        }
        //check block
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int col=3*i;
                int row=3*j;
                vector<bool> store(9,false);
                for(int c=col;c<col+3;c++){
                    for(int r=row;r<row+3;r++){
                        if(board[c][r]=='.') continue;
                        int tmp=board[c][r]-'0';
                        if(tmp==0||store[tmp-1]) return false;
                        store[tmp-1]=true;
                    }
                }
            }
        }
        return true;
        
    }
};