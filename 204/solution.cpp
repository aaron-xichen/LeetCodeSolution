#include "../solution.h"
class Solution {
public:
    int countPrimes(int n) {
        vector<int> v;
        for(int i=2; i<n; i++){
            bool is_prime = true;
            int bound = sqrt(i);
            for(int j=0; j<(int)v.size() && v[j] <= bound; j++){
                if(i % v[j] == 0){
                    is_prime = false;
                    break;
                }
            }
            if(is_prime)
                v.push_back(i);
        }
        return v.size();
    }
};
