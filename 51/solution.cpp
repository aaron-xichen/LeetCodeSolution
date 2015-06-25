#include "../solution.h"
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int bound = 0;
        char c[n+1];
        memset(c, '.', n);
        c[n] = '\0';
        string s = string(c);
        for(int i=0; i<n; i++)
            bound = (bound<<1) + 1;
        cout<<bound<<endl;
        cout<<s<<endl;
        vector<vector<string> > all_solutions;
        vector<int> solution;
        recursion(0, 0, 0, bound, s, solution, all_solutions);
        return all_solutions;
    }

    void recursion(int row, int left, int right, int bound, string &s, vector<int> &solution, vector<vector<string> > &all_solutions){
        if(row == bound){
            vector<string> current_solution;
            for(int i=0; i<(int)solution.size(); i++){
                int idx = (int)log2(solution[i]);
                s[idx] = 'Q';
                current_solution.push_back(s);
                s[idx] = '.';
            }
            all_solutions.push_back(current_solution);
        }else{
            int pos = ~(row | left | right) & bound;
            // cout<<"row:"<<row<<"left"<<left<<"right"<<right<<endl;
            // cout<<"pos"<<pos<<endl;
            while(pos){
                int p = pos & (~pos + 1);
                pos = pos - p;
                solution.push_back(p);
                recursion(row|p, (left|p)<<1, (right|p)>>1, bound, s, solution, all_solutions);
                solution.pop_back();
            }
        }
    }
};
