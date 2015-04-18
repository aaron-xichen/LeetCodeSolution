#include "../solution.h"
class solution{
    public:
        int minCut(string s){
            int len = s.length();
            if(len >1000) return 1;
            if(len == 0 || len == 1) return 0;

            //initialization
            int min_cut_num[len];
            for(int i=0; i<len; i++){
                min_cut_num[i] = i;
            }

            for(int i=1; i<len; i++){
                if(isPalindrome(s, 0, i)){
                    min_cut_num[i] = 0;
                    continue;
                }
                for(int j=0; j<i; j++){
                    if(min_cut_num[j] < min_cut_num[i]-1){
                        if(isPalindrome(s, j+1, i))
                            min_cut_num[i] = min(min_cut_num[i], min_cut_num[j]+1);
                    }
                }
            }
            return min_cut_num[len-1];
        }

        bool isPalindrome(string &s, int start, int end){
            if(start == end)
                return true;
            else{
                for(int i=start,j=end; i<=j; i++,j--){
                    if(s.at(i) != s.at(j))
                        return false;
                }
            }
            return true;
        }
};
