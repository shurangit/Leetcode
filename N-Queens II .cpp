class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        if(n==0) return res;
        vector<int> row;
        helper(n,0,res,row);
        return res;
    }
     void helper(int n, int coll, int& res, vector<int> &row){
        if(coll==n) {
           res++;
            return;
        }
        for(int rowl=0;rowl<n;rowl++){
            if(isValid(row,coll,rowl)){
                row.push_back(rowl);
                helper(n,coll+1,res,row);
                row.pop_back();
            }
        }
    }
    //used to decide whether vaild 1.rowl!=row[coll] 2. abs(i-coll)!=abs(row[i)-rowl)
    bool isValid(vector<int>& row, int coll, int rowl){
        if(coll<row.size()) return false;
        for(int i=0;i<row.size();i++){
            if(rowl==row[i]||abs(i-coll)==abs(row[i]-rowl)) return false;
        }
        return true;
    }
};