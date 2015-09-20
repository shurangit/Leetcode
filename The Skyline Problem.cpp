class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> res;
        vector<pair<int,int>> height;
        for(auto n:buildings){
            height.push_back(make_pair(n[0],-n[2])); //start->height is negtive
            height.push_back(make_pair(n[1],n[2])); //end: height is positive
        }
        sort(height.begin(),height.end());
        multiset<int> heap; //auto sort
        heap.insert(0);
        int pre=0, cur=0; 
        for(auto n:height){
            if(n.second<0) {
                heap.insert(-(n.second));
            }else{
                heap.erase(heap.find(n.second));
            }
            cur=*heap.rbegin(); //max vlaue in heap
            if(cur!=pre){
                res.push_back(make_pair(n.first,cur));
                pre=cur;
            }
        }
        return res;
    }
};