#include <iostream>
#include <vector>
using namespace std;
class solution{
    public:
        int majorityElement(vector<int> &num){
            int counter = 0;
            int ele = -1;
            for(int i=0; i<(int)num.size(); i++){
                if(counter == 0){
                    counter = 1;
                    ele = num[i];
                }else if(ele != num[i]){
                    counter--;
                }else{
                    counter++;
                }
            }
            return ele;
        }
};
