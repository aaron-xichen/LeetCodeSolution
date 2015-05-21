#include "../solution.h"
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // trivial case
        if(node == NULL)
            return NULL;

        int SIZE = 100;
        vector<UndirectedGraphNode*> vertexs =
            vector<UndirectedGraphNode*>(SIZE);
        for(int i=0; i<SIZE; i++){
            vertexs[i] = new UndirectedGraphNode(-1);
        }
        recursion(vertexs, node);
        return vertexs[node->label];
    }

    void recursion(vector<UndirectedGraphNode*> &vertexs, UndirectedGraphNode *node){
        if(vertexs[node->label]->label == -1)
            vertexs[node->label]->label = node->label;

        // assign the edge
        for(int i=0; i<(int)node->neighbors.size(); i++){
            int neighbour_label = node->neighbors[i]->label;
            vertexs[node->label]->neighbors.push_back(vertexs[neighbour_label]);

            // whether to recusion
            if(vertexs[neighbour_label] != NULL)
                recursion(vertexs, node->neighbors[i]);
        }

        // beign to recursion
        // for(int i=0; i<(int)node->neighbors.size(); i++){

        // }
    }
};
