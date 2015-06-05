#include "../solution.h"
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        int max_points = 0;
        for(int i=0; i<len; i++){
            if(max_points >= len - i )
                return max_points;
            Point p1 = points[i];
            int same_point_num = 1;
            unordered_map<float, int> slope2num2;
            for(int j=i+1; j<len; j++){
                Point p2 = points[j];
                if(p1.x == p2.x && p1.y == p2.y)
                    same_point_num++;
                else{
                    float slope = compute_slope(p1, p2);
                    if(slope2num2.find(slope) == slope2num2.end())
                        slope2num2[slope] = 1;
                    else
                        slope2num2[slope]++;
                }
            }
            int maximum = 0;
            for(unordered_map<float,int>::iterator it=slope2num2.begin(); it != slope2num2.end(); it++){
                maximum = max(it->second, maximum);
            }
            cout<<same_point_num<<endl;
            max_points = max(maximum+same_point_num, max_points);
        }
        return max_points;
    }

    float compute_slope(Point &p1, Point &p2){
        if(p1.x == p2.x)
            return INT_MAX;
        else
            return float(p1.y-p2.y) / (p1.x-p2.x);
    }
};
