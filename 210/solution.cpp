#include "../solution.h"
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        // build the graph
        vector<vector<int> > graph(numCourses, vector<int>());
        for(int i=0; i<(int)prerequisites.size(); i++){
            pair<int, int> edge = prerequisites[i];
            graph[edge.second].push_back(edge.first);
        }

        // dfs
        // -1 is white node, 0 is gray node, 1 is black node
        vector<int> flags(numCourses, -1);
        vector<int> trace;
        for(int i=0; i<numCourses; i++){
            if(flags[i] == -1){
                if(!dfs(i, graph, flags, trace)){
                    trace.clear();
                    return trace;
                }
            }
        }
        reverse(trace.begin(), trace.end());
        return trace;
    }

    bool dfs(int idx, vector<vector<int> > &graph, vector<int> &flags, vector<int> &trace){
        flags[idx] = 0;
        vector<int> neighbours = graph[idx];
        for(int i=0; i<(int)neighbours.size(); i++){
            int neig_idx = neighbours[i];
            if(0 == flags[neig_idx])
                return false;
            else if(-1 == flags[neig_idx]){
                bool ok = dfs(neig_idx, graph, flags, trace);
                if(!ok){
                    return false;
                }
            }
        }
        flags[idx] = 1;
        trace.push_back(idx);
        return true;
    }
};
