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
    int maxPoints(vector<Point> &points) {
        if(points.size() < 3)
            return points.size();
        int mp = 2;
        int i = 0;
        while(i <= points.size()-3)
        {
            int self = 1;
            int samex = 0;
            int diffx = 0;
            map<double, int> kmap;
            int x = points[i].x;
            int y = points[i].y;

            int j = i+1; 
            while(j <= points.size()-1)
            {
                if(points[j].x == x && points[j].y == y)    
                    self++;
                else if(points[j].x == x)
                    samex++;
                else
                {
                    double k = (double(points[j].y - y))/(double(points[j].x - x));     
                    if(kmap.find(k)!=kmap.end())
                        kmap[k] ++;
                    else
                        kmap[k] = 1;
                    if(kmap[k]>diffx)
                        diffx = kmap[k];
                }
                j++; 
            }

            int localmp = max(diffx,samex) + self; 
            if(localmp > mp)
                mp = localmp;
            i++;
        }
        return mp;
    }
};
