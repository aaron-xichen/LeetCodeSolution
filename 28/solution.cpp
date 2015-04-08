#include "../solution.h"
class solution{
    public:
        int strStr(char *haystack, char *needle){
            if(NULL == haystack || NULL == needle) return -1;
            int len_haystack = strlen(haystack);
            int len_needle = strlen(needle);
            // cout<<"len_haystack" <<len_haystack<<endl;
            // cout<<"len_needle" << len_needle<<endl;
            if(0 == len_needle)
                return 0;
            else if(0 == len_haystack)
                return -1;
            int ptr_haystack = 0;
            int ptr_needle = 0;
            while(true){
                if(ptr_needle == len_needle || ptr_haystack == len_haystack) break;
                if(*(haystack+ptr_haystack++) == *(needle+ptr_needle)){
                    ptr_needle++;
                    // cout<<ptr_haystack<<" " <<ptr_needle<<endl;
                }else{
                    ptr_haystack -= ptr_needle;
                    ptr_needle = 0;
                }
            }
            if(ptr_haystack == len_haystack && ptr_needle != len_needle){
                // cout<<"in"<<endl;
                return -1;
            }else
                return ptr_haystack-len_needle;
        }
};
