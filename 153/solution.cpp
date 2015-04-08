#include "../solution.h"
class solution{
    public:
        int findMin(vector<int> &num){
            for(int i=0; i<(int)num.size()-1; i++){
                if(num[i] > num[i+1])
                    return num[i+1];
            }
            return num[0];
        }
};
