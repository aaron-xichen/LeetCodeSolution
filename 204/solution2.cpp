#include "../solution.h"
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> is_prime(n, true);
        int counter = n-2;
        int bound = sqrt(n);
        for(int i=2; i<=bound; i++){
            if(is_prime[i]){
                for(int j=i*i; j<n; j+=i){
                    if(is_prime[j]){
                        is_prime[j] = false;
                        counter--;
                    }
                }
            }
        }
        return counter;
    }
};
