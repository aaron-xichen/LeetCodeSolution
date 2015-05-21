#include "../solution.h"
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // trivial case
        if(node == NULL)
            return NULL;

        unordered_map<int, UndirectedGraphNode*> vertexs;
        unordered_set<int> visited_vertex;
        vertexs[node->label] = new UndirectedGraphNode(node->label);
        recursion(vertexs, visited_vertex, node);
        return vertexs[node->label];
    }

    void recursion(unordered_map<int, UndirectedGraphNode*> &vertexs,
            unordered_set<int> &visited_vertex, UndirectedGraphNode *node){

        visited_vertex.insert(node->label);
        for(int i=0; i<(int)node->neighbors.size(); i++){
            int neighbour_label = node->neighbors[i]->label;
            if(vertexs.find(neighbour_label) == vertexs.end())
                vertexs[neighbour_label] = new UndirectedGraphNode(neighbour_label);
            vertexs[node->label]->neighbors.push_back(vertexs[neighbour_label]);
            if(visited_vertex.find(neighbour_label) == visited_vertex.end())
                recursion(vertexs, visited_vertex, node->neighbors[i]);
        }
    }
};
