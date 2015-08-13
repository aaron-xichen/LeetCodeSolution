#include "../solution.h"
#include <utility>
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> node2id;
        vector<vector<int> > graphs;
        int pair_num = prerequisites.size();

        for(int i=0; i<pair_num; i++){
            // add node
            int first_node = prerequisites[i].first;
            if(node2id.find(first_node) == node2id.end()){
                node2id.insert(make_pair(first_node, node2id.size()));
                graphs.resize(node2id.size());
            }
            int second_node = prerequisites[i].second;
            if(node2id.find(second_node) == node2id.end()){
                node2id.insert(make_pair(second_node, node2id.size()));
                graphs.resize(node2id.size());
            }

            // add edge
            graphs[node2id.find(first_node)->second].push_back(node2id.find(second_node)->second);
        }

        // DFS
        int node_num = graphs.size();
        // 0 - white node, 1 - gray node, 2 - black node
        vector<int> trace(node_num, 0);
        for(int i=0; i<node_num; i++){
            if(trace[i] == 2) continue;
            else{
                bool has_circle = dfs(graphs, trace, i);
                if(has_circle) return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int> > &graphs, vector<int> &trace, int cur_node){
        // find gray node, means circle exists
        if(trace[cur_node] == 1) return true;
        else if(trace[cur_node] == 2) return false;
        else{
            // otherwise expand current node
            trace[cur_node] = 1;
            for(int i=0; i<(int)graphs[cur_node].size(); i++){
                bool has_circle = dfs(graphs, trace, graphs[cur_node][i]);
                if(has_circle) return true;
            }
            trace[cur_node] = 2;
            return false;
        }

    }
};
