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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0;        
        while(i < intervals.size() && intervals[i].end<newInterval.start)
        {
            res.push_back(intervals[i]); 
            i++;
        }

        if(i == intervals.size())
        {
            res.push_back(newInterval);
            return res;
        }

        // next, newInterval.start<=intervals[i].end
        int start = min(intervals[i].start, newInterval.start);

        while(i<intervals.size() && newInterval.end>=intervals[i].start)
            i++;

        res.push_back(Interval(start, max((i==0?INT_MIN:intervals[i-1].end), newInterval.end)));

        while(i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};
