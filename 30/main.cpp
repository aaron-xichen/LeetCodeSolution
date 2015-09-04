#include "./solution2.cpp"
int main(){
    Solution sl = Solution();
    string num[] = {"aa", "aa", "aa"};
    vector<string> nums(num, num + sizeof(num) / sizeof(num[0]));
    string  s = "aaaaaaaa";

    vector<int> r = sl.findSubstring(s, nums);
    for(int i=0; i<(int)r.size(); i++){
        cout<<r[i]<<" ";
    }
}
