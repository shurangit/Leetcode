class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g=graph(numCourses, prerequisites);
        vector<int> d=degree(g);
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++){
                if(!d[j]) break;
            }
            if(j==numCourses) return false;
            d[j]=-1;
            for(auto itr = g[j].begin(); itr != g[j].end(); itr++){
                d[*itr]--;
            }
        }
        return true;
        
    }
    
    vector<vector<int>> graph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<vector<int>> res(numCourses);
        for(auto pre:prerequisites){
            res[pre.second].push_back(pre.first);
        }
        return res;
    }
    
    vector<int> degree(vector<vector<int>>& graph){
        vector<int> res(graph.size(),0);
        for(auto neigh: graph){
            for(auto nei: neigh){
                res[nei]++;
            }
        }
        return res;
    }
};

