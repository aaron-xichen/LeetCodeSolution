#include "./solution2.cpp"
int main(){
    UndirectedGraphNode *root = new UndirectedGraphNode(10);
    UndirectedGraphNode *child1 = new UndirectedGraphNode(15);
    UndirectedGraphNode *child2 = new UndirectedGraphNode(2);
    UndirectedGraphNode *child3 = new UndirectedGraphNode(35);
    UndirectedGraphNode *child4 = new UndirectedGraphNode(80);
    root->neighbors.push_back(child1);
    root->neighbors.push_back(child2);
    root->neighbors.push_back(child3);
    root->neighbors.push_back(child4);

    Solution sl = Solution();
    UndirectedGraphNode *result = sl.cloneGraph(root);
    cout<<result->label<<endl;
    for(int i=0; i<(int)result->neighbors.size(); i++){
        cout<<result->neighbors[i]->label<<" ";
    }
}

