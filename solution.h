#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<map>
#include<stdlib.h>
#include<limits>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x):val(x), left(NULL), right(NULL), next(NULL){}

};

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e){}
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

