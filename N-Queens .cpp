class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if(n==0) return res;
        vector<string> sol;
        vector<int> row;
        helper(n,0,res,sol,row);
        return res;
    }
    // coll->collth col res->total res, sol->single res, row->store row in each column
    void helper(int n, int coll, vector<vector<string>>& res, vector<string>& sol, vector<int> &row){
        if(coll==n) {
            res.push_back(sol);
            return;
        }
        for(int rowl=0;rowl<n;rowl++){
            if(isValid(row,coll,rowl)){
                string s(n,'.');
                s[rowl]='Q';
                sol.push_back(s);
                row.push_back(rowl);
                helper(n,coll+1,res,sol,row);
                sol.pop_back();
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