#include "../solution.h"
bool compare(string &str1, string &str2){
    return str1 + str2 > str2 + str1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_vec;
        for(int i=0; i<(int)nums.size(); i++)
            str_vec.push_back(to_string(nums[i]));
        sort(str_vec.begin(), str_vec.end(), compare);
        string str = "";
        for(int i=0; i<(int)str_vec.size(); i++){
            if(str.empty() && str_vec[i] == "0") continue;
            str += str_vec[i];
        }
        if(str.empty())
            return "0";
        return str;
    }
};
