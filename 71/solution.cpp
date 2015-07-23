#include "../solution.h"
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        int beg = 1;
        int cur = 1;
        while(cur <= (int)path.length()){
            if(cur == (int)path.length() || path[cur] == '/'){
                if(cur - beg> 0){
                    string component = path.substr(beg, cur - beg);
                    if(component != ".." && component != ".")
                        components.push_back(component);
                    else if(component == ".." && !components.empty())
                        components.pop_back();
                }
                beg = cur + 1;
            }
            cur++;
        }
        string result;
        for(int i=0; i<(int)components.size(); i++){
            result += "/";
            result += components[i];
        }
        return result.empty() ? "/" : result;

    }
};
