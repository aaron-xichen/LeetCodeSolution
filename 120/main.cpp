#include "./solution.cpp"
int main(){
    vector<vector<int> > triangle;
    int row1[] ={2};
    int row2[] ={3, 4};
    int row3[] ={6, 5, 7};
    int row4[] ={4, 1, 8, 3};

    vector<int> r1(row1, row1+sizeof(row1)/sizeof(row1[0]));
    vector<int> r2(row2, row2+sizeof(row2)/sizeof(row2[0]));
    vector<int> r3(row3, row3+sizeof(row3)/sizeof(row3[0]));
    vector<int> r4(row4, row4+sizeof(row4)/sizeof(row4[0]));

    triangle.push_back(r1);
    triangle.push_back(r2);
    triangle.push_back(r3);
    triangle.push_back(r4);

    solution sl = solution();
    int minimumTotal = sl.minimumTotal(triangle);
    cout<<minimumTotal<<endl;
}
