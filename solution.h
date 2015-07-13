#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<stdlib.h>
#include<limits>
#include<cmath>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
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
