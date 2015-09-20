class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board.size() != 9 || board[0].size() !=9)  
        return;  
        helper(board,0,0);  
    }
    
    bool helper(vector<vector<char>>& board,int col,int row){
        //decide boundary
        if(row>=9) return helper(board,col+1,0); //change to another column
        if(col==9) return true;
         
        if(board[col][row]=='.'){
            for(int i=1;i<=9;i++){ //try 1~9
                board[col][row]=(char) (i+'0');
                if(isValid(board,col,row)) {//valid
                    if(helper(board,col,row+1)) return true;
                }
                board[col][row]='.'; //not valid and reset
                
            }
        }
        else{
            return helper(board,col,row+1);
        }
        return false;
        
    }
    
    bool isValid(vector<vector<char>>& board,int coll,int rowl){
        char tmp=board[coll][rowl];
        if(tmp<'1'||tmp>'9') return false;
        //check col,row
        for(int i=0;i<9;i++){
            if(board[i][rowl]==tmp&&i!=coll) return false;
            if(board[coll][i]==tmp&&i!=rowl) return false;
        }
        //check 3*3
        int col=coll/3*3, row=rowl/3*3;
        for(int i=col;i<col+3;i++){
            for(int j=row;j<row+3;j++){
                if(board[i][j]==tmp&&(i!=coll||j!=rowl)) return false;
            }
        }
        return true;
    }
};