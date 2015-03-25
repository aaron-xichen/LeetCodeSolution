#include "solution.cpp"
int main(){
    vector<vector<char> > matrix;
    char row1[] = {'0', '0', '1', '1'};
    char row2[] = {'1', '0', '1', '1'};
    char row3[] = {'1', '1', '1', '1'};
    // char row4[] = {'0', '1', '1', '1'};
    // char row5[] = {'0', '0', '0', '0'};

    vector<char> v1(&row1[0], &row1[4]);
    vector<char> v2(&row2[0], &row2[4]);
    vector<char> v3(&row3[0], &row3[4]);
    // vector<char> v4(&row4[0], &row4[3]);
    // vector<char> v5(&row5[0], &row5[3]);

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    // matrix.push_back(v4);
    // matrix.push_back(v5);
    // matrix.push_back(v1);
    solution sl = solution();
    int s = sl.maximalRectangle(matrix);
    cout<<s<<endl;

}
