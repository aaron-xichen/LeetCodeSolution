#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
class utils{
    public:
        void print(vector<vector<int> > data){
            if(data.empty()) return;
            for(int i=0; i<(int)data.size(); i++){
                for(int j=0; j<(int)data[i].size(); j++){
                    cout<<data[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};
