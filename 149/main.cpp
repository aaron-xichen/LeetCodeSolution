#include "./solution.cpp"
int main(){
    Point p1 = Point(0,0);
    vector<Point> ps;
    ps.push_back(p1);

    Solution sl = Solution();
    cout<<sl.maxPoints(ps)<<endl;
}
