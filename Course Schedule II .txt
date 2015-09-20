class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph=make_graph(numCourses, prerequisites);
        vector<int> degree=build_degree(graph);
        queue<int> que;
        for(int i=0;i<degree.size();i++){
            if(!degree[i]) que.push(i);
        }
        while(!que.empty()){
            int tmp=que.front();
            que.pop();
            res.push_back(tmp);
            for(auto nei:graph[tmp]){
                degree[nei]--;
                if(!degree[nei]) que.push(nei);
            }
            numCourses--; //used to find out whether take all courses
        }
        if(numCourses) res.clear();
        return res;
    }
    
    vector<vector<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites){
        vector<vector<int>> graph(numCourses);
        for(auto pre:prerequisites){
            graph[pre.second].push_back(pre.first);
        }
        return graph;
    }
    
    vector<int> build_degree(vector<vector<int>>& graph){
        vector<int> degree(graph.size(),0);
        for(auto neigh: graph){
            for(auto nei:neigh){
                degree[nei]++;
            }
        }
        return degree;
    }
};