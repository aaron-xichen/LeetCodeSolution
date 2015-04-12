#include "../solution.h"
class solution{
    public:
        int ladderLength(string start, string end, unordered_set<string>&dict){
            if(start.empty() || end.empty() || dict.empty())
                return 0;
            queue<string> path;
            string delimiter = "";
            path.push(start);
            dict.erase(start);
            dict.insert(end);
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
                vector<string> to_delete;
                for(unordered_set<string>::iterator it=dict.begin(); it!=dict.end(); ++it){
                    if(isAdjacent(*it, current)){
                        // cout<<*it<<" "<<current<<endl;
                        if(*it == end) return step+1;
                        path.push(*it);
                        to_delete.push_back(*it);
                    }
                }
                //delete
                for(int i=0; i<(int)to_delete.size(); i++){
                    dict.erase(to_delete[i]);
                }
            }
            return 0;
        }

        bool isAdjacent(string str1, string str2){
            if(str1.empty() || str2.empty()) return false;
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
