/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        bool isIn=false;
        
        for(int i=0;i<intervals.size();i++){
            if(isIn) {
                res.push_back(intervals[i]);
                continue;
            }
            //insert new before cur inter
            if(newInterval.end<intervals[i].start){
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                isIn=true;
                continue;
            }
            //insert after cur
            if(intervals[i].end<newInterval.start){
                res.push_back(intervals[i]);
                continue;
            }
            //need merge
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
            
        }
        if(!isIn) res.push_back(newInterval);
        return res;
    }
};