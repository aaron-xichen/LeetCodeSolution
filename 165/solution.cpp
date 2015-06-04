#include "../solution.h"
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int ver1 = 0;
        int ver2 = 0;
        int pos1 = 0;
        int pos2 = 0;
        while(true){
            while(pos1 < len1 && version1[pos1] != '.'){
                ver1 = 10 * ver1 + (version1[pos1++] - '0');
            }
            while(pos2 < len2 && version2[pos2] != '.'){
                ver2 = 10 * ver2 + (version2[pos2++] - '0');
            }
            if(ver1 > ver2)
                return 1;
            else if(ver1 < ver2)
                return -1;
            else{
                pos1 ++;
                pos2 ++;
                ver1 = 0;
                ver2 = 0;
            }
            if(pos1 >= len1 && pos2 >= len2)
                return 0;
        }
    }
};
