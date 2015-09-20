/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.empty()) return 0;
        int maxi=1;
        for(int i=0;i<points.size()-1;i++){
            int maxx=0,same=0,ver=0;
            unordered_map<float,int> hash;//key->slope,value->count
            for(int j=i+1;j<points.size();j++){
                if(points[i].x==points[j].x){
                    //same point
                    if(points[i].y==points[j].y){
                       same++; 
                    }
                    //verical
                    else ver++;
                    continue;
                }
                float slope=(float) (points[j].y-points[i].y)/(points[j].x-points[i].x);
                hash[slope]++;
                maxx=max(maxx,hash[slope]); //point[i] max
            }
            maxx=max(maxx,ver)+same+1; //compare slope&&verical
            maxi=max(maxi,maxx);
        }
        return maxi;
    }
};