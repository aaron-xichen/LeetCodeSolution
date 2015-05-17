#include "./solution2.cpp"
int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int len = sizeof(height)/sizeof(height[0]);
    vector<int> heights(height, height+len);
    Solution sl = Solution();
    cout<<sl.trap(heights)<<endl;
}
