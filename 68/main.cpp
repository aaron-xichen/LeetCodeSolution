#include "./solution.cpp"
int main(){
    string strs[] = {"What", "must", "be", "shall", "be."};
    int len = sizeof(strs) / sizeof(strs[0]);
    vector<string> strs_vec(strs, strs+len);


    Solution sl = Solution();
    vector<string> just = sl.fullJustify(strs_vec, 12);
    for(int i=0; i<(int)just.size(); i++){
        cout<<just[i]<<endl;
    }
}
