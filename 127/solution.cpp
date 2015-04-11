#include "../solution.h"
class solution{
    // this solution will TLE
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict){
            if(start.empty() || end.empty() || dict.empty())
                return 0;
            int len = dict.size();
            vector<vector<int> > adjacent;
            vector<string> dict_array;
            vector<int> tmp;
            for( unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); ++it){
                adjacent.push_back(tmp);
                dict_array.push_back(*it);
            }
            adjacent.push_back(tmp);
            adjacent.push_back(tmp);

            int path = 2;
            if(isAdjacent(start,end)){
                return path;
            }
            //construct the graph
            // 0 represents the source, 1-len represent the dict_vertex, len+1 represents the dist
            for(int i=0; i<len; i++){
                if(isAdjacent(start, dict_array[i])){
                    adjacent[0].push_back(i+1);
                    adjacent[i+1].push_back(0);
                }
                if(isAdjacent(end,dict_array[i])){
                    adjacent[i+1].push_back(len+1);
                    adjacent[len+1].push_back(i+1);
                }
            }
            for(int i=0; i<len; i++){
                for(int j=i+1; j<len; j++){
                    if(isAdjacent(dict_array[i], dict_array[j])){
                        adjacent[i+1].push_back(j+1);
                        adjacent[j+1].push_back(i+1);
                    }
                }
            }
            //print info
            // cout<<"0:"<<start<<endl;
            // for(int i=0; i<(int)dict_array.size(); i++){
                // cout<<i+1<<":"<<dict_array[i]<<endl;
            // }
            // cout<<len+1<<":"<<end<<endl;

            // for(int i=0; i<len+2; i++){
                // cout<<i<<":";
                // for(int j=0; j<(int)adjacent[i].size(); j++){
                    // cout<<adjacent[i][j]<<" ";
                // }
                // cout<<endl;
            // }

            //begin to BFS search
            bool visited[len+1];
            int dist_to[len+1];
            queue<int> q;
            for(int i=0; i<len+1; i++){
                visited[i] = false;
                dist_to[i] = -1;
            }
            q.push(0);
            dist_to[0] = 1;
            while(!q.empty()){
                int current = q.front();
                // cout<<"current"<<current<<endl;
                q.pop();
                if(visited[current])
                    continue;
                visited[current] = true;
                // cout<<"len"<<adjacent[current].size()<<endl;
                for(int i=0; i<(int)adjacent[current].size(); i++){
                    int adj = adjacent[current][i];
                    // cout<<adj<<endl;
                    if(len+1 == adj) return dist_to[current] + 1;
                    dist_to[adj] = dist_to[current] + 1;
                    q.push(adj);
                }
            }
            return 0;
        }

        bool isAdjacent(string str1, string str2){
            if(str1.empty() || str2.empty()) return -1;
            int len = str1.length();
            bool isDifferent = false;
            for(int i=0; i<len; i++){
                if(str1.at(i) != str2.at(i)){
                    if(!isDifferent)
                        isDifferent = true;
                    else
                        return false;
                }
            }
            return isDifferent;
        }
};
