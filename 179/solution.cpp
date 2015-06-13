#include "../solution.h"
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // classify with digits nums
        vector<vector<int> > len2value(9, vector<int>());
        for(int i=0; i<(int)nums.size(); i++){
            int digits_num = find_digits_nums(nums[i]);
            len2value[digits_num-1].push_back(nums[i]);
        }

        // sort
        cout<<"sorting"<<endl;
        for(int i=0; i<9; i++){
            vector<int> ele = len2value[i];
            sort(ele.begin(), ele.end());
        }

        // insert, pair<value, value_length>
        cout<<"inserting"<<endl;
        vector<pair<int, int> > l;
        for(int i=0; i<9; i++){
            if(len2value[i].empty()) continue;
            for(int j=0; j<(int)len2value[i].size(); j++){
                int value = len2value[i][j];
                // cout<<value<<" ";
                insert(l, value, i+1);
            }
            // cout<<endl;
        }

        // concatenate
        cout<<"concatenating"<<endl;
        string str = "";
        for(int i=0; i<(int)l.size(); i++){
            str += to_string(l[i].first);
        }

        return str;
    }

    int find_digits_nums(int num){
        int n=1;
        if(num > 100000000){num /= 100000000; n += 8;}
        if(num > 10000){num /= 10000; n += 4;}
        if(num > 100){num /= 100; n += 2;}
        if(num > 10){num /= 10; n += 1;}
        return n;
    }

    void insert(vector<pair<int, int> > &l, int value, int value_length){
        if(l.empty()){
            l.push_back(pair<int, int>(value, value_length));
            return;
        }
        int l_length = l.size();
        for(int i=0; i<l_length; i++){
            int remain_length = value_length;
            int end_index = i;
            while(end_index < l_length && l[end_index].second < remain_length)
                    remain_length -= l[end_index++].second;

            // cout<<"end_index"<<end_index<<endl;
            // cout<<"begin_index"<<i<<endl;
            if(l[end_index].second == remain_length){
                int tmp_value = 0;
                int total_len = 0;
                for(int j=end_index; j>=i; j--){
                    int current_value = l[j].first;
                    int current_value_length = l[j].second;
                    int offset = (int)pow(10, total_len);
                    if(total_len + current_value_length == 10){
                        int part1 = INT_MAX / offset;
                        int part2 = INT_MAX - part1*offset;
                        // cout<<part1<<endl;
                        // cout<<part2<<endl;
                        // check overfloat
                        if(part1 < current_value ||
                                (part1 == current_value && tmp_value > part2)){
                            tmp_value = INT_MAX;
                            break;
                        }

                    }
                    tmp_value = current_value*offset + tmp_value;
                    total_len += current_value_length;
                }
                cout<<"value"<<value<<endl;
                cout<<"tmp_value"<<tmp_value<<endl;
                if(value > tmp_value){
                    l.insert(l.begin()+i, pair<int, int>(value, value_length));
                    for(int k=0; k<(int)l.size(); k++)
                        cout<<l[k].first<<" ";
                    cout<<endl;
                    return;
                }
            }
        }
        l.insert(l.end(), pair<int, int>(value, value_length));

    }
};
