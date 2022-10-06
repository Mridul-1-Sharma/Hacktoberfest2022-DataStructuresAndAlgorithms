// Name of Problem = Max Points on a Line

// Problem Link : https://leetcode.com/problems/max-points-on-a-line/


#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct Line {
    double r;  // ratio ; slope
    double t;  // translation
    
    Line(Point p, Point q) { // math
        if (q.x == p.x) r = 1e20, t = p.x;
        else 
        {
            r = (double) (q.y-p.y) / (double) (q.x-p.x);
            t = p.y - p.x * r;
        }
    }
};

bool operator < (const Line& a, const Line& b) {
    return a.r == b.r ? a.t < b.t : a.r < b.r;
}

bool operator == (const Line& a, const Line& b) {
    return a.r == b.r && a.t == b.t;
}

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
        
        map<Line, set<Point*> > line_map;
        for (auto & a : points)
        for (auto & b : points)
        {
            Line line(a,b);
            line_map[line].insert(&a);
            line_map[line].insert(&b);
        }
        
        int ret = 1;
        for (auto & pr : line_map) ret = max(ret,(int)pr.second.size());
        
        return ret;
    }
};