#include "../solution.h"
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        vector<int> trace(rows * cols, 0);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == '0')
                    trace[i * cols + j] = -1;
                else
                    trace[i * cols + j] = i * cols + j;
            }
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                int cur = i * cols + j;

                if(grid[i][j] == '0')
                    continue;

                // right
                if(j + 1 < cols && grid[i][j+1] == '1')
                    addEdge(trace, cur + 1, cur);

                // bottom
                if(i + 1 < rows && grid[i+1][j] == '1')
                    addEdge(trace, cur + cols, cur);
            }
        }

        int cluster = 0;
        for(int i=0; i<(int)trace.size(); i++){
            if(trace[i] == i)
                cluster++;
        }
        return cluster;
    }

    void addEdge(vector<int> &trace, int from, int to){
        trace[find(trace, from)] = find(trace, to);
    }

    int find(vector<int> &trace, int ptr){
        if(trace[ptr] == ptr)
            return ptr;
        trace[ptr] = find(trace, trace[ptr]);
        return trace[ptr];
    }
};
