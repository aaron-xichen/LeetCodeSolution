#include "../solution.h"
struct SearchNode{
    string value;
    int depth;
    vector<SearchNode*> pre;
    SearchNode(string v, int d):value(v), depth(d){};
};

class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        SearchNode *DELIMITER = NULL;
        int best_solution_depth = -1;
        int current_depth = 1;

        unordered_map<string, SearchNode*> m;
        queue<SearchNode*> candidates;

        SearchNode *begin_node = new SearchNode(start, 0);
        m.insert(pair<string, SearchNode*>(start, begin_node));

        candidates.push(begin_node);
        candidates.push(DELIMITER);
        dict.erase(start);
        while(!candidates.empty()){
            // update the depth, in order to prune
            SearchNode *current_node = candidates.front();
            candidates.pop();
            if(current_node == DELIMITER){
                current_depth++;
                if(!candidates.empty())
                    candidates.push(DELIMITER);
                continue;
            }

            // prune
            if(-1 != best_solution_depth && current_depth > best_solution_depth)
                break;

            // expand current node
            vector<string> to_delete;
            string old_str = current_node->value;
            for(int i=0; i<(int)old_str.size(); i++){
                char old_char = old_str[i];
                string new_str = old_str;
                for(int j=0; j<26; j++){
                    char new_char = 'a' + j;
                    if(old_char != new_char){
                        // construct new string
                        new_str[i] = new_char;

                        // find a solution
                        if(new_str == end && -1 == best_solution_depth){
                            best_solution_depth = current_depth;
                        }

                        // already exist
                        if(m.find(new_str) != m.end() &&
                                (m.find(new_str)->second->depth > current_depth || new_str ==end)){
                            m.find(new_str)->second->pre.push_back(current_node);
                        }
                        else if(dict.find(new_str) != dict.end()){
                            SearchNode *new_node = new SearchNode(new_str, current_depth+1);
                            new_node->pre.push_back(current_node);
                            candidates.push(new_node);
                            m.insert(pair<string, SearchNode*>(new_str, new_node));
                            to_delete.push_back(new_str);
                        }
                    }
                }
            }

            for(int i=0; i<(int)to_delete.size(); i++){
                dict.erase(to_delete[i]);
            }
        }

        // construct the solutions
        vector<vector<string> > all_solutions;
        vector<string> solution;
        if(m.find(end) != m.end()){
            SearchNode *end_node = m.find(end)->second;
            recusion(end_node, solution, all_solutions);
            for(int i=0; i<(int)all_solutions.size(); i++){
                reverse(all_solutions[i].begin(), all_solutions[i].end());
            }
        }
        return all_solutions;
    }

    void recusion(SearchNode *current_node, vector<string> &solution,
            vector<vector<string> > &all_solutions){
        solution.push_back(current_node->value);
        if(current_node->pre.empty())
            all_solutions.push_back(solution);
        else{
            for(int i=0; i<(int)current_node->pre.size(); i++){
                recusion(current_node->pre[i], solution, all_solutions);
            }
        }
        solution.pop_back();
    }
};
