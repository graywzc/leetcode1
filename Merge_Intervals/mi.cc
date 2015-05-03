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

    bool comp(Interval a, Interval b)
    {
        return a.start<b.start; 
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        
        vector<Interval> res;
        if(intervals.empty())
            return res;

        int start = intervals[0].start;
        int end = intervals[0].end;

        int i = 1;
        while(i < intervals.size())
        {
            if(intervals[i].start>end)
            {
                res.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else
            {
                end = max(end, intervals[i].end);
            }
            i++; 
        }

        res.push_back(Interval(start,end));
        return res;
    }
};
