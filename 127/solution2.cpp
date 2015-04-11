#include "../solution.h"
class solution{
    public:
        int ladderLength(string start, string end, unordered_set<string>&dict){
            if(start.empty() || end.empty() || dict.empty())
                return 0;
            queue<string> path;
            int len = start.length();
            string delimiter = "";
            path.push(start);
            dict.erase(start);
            dict.erase(end);
            path.push(delimiter);
            int step = 1;
            while(!path.empty()){
                string current = path.front();
                path.pop();
                if(delimiter == current){
                    step++;
                    if(!path.empty()){
                        path.push(delimiter);
                    }
                }

                //search
                for(int i=0; i<len; i++){
                    for(int j=0; j<26; j++){
                        char c = current[i];
                        current[i] = 'a' + j;
                        if(current == end){
                            return step+1;
                        }
                        if(dict.find(current) != dict.end()){
                            path.push(current);
                            dict.erase(current);
                        }
                        current[i] = c;
                    }
                }
            }
            return 0;
        }
};
