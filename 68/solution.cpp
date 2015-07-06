#include "../solution.h"
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int pos = 0;
        int len = words.size();
        vector<string> lines;
        while(pos < len){
            int length_sofar = words[pos].length();
            int next = pos + 1;
            while(next < len && length_sofar + 1 + (int)words[next].length() <= maxWidth){
                length_sofar += 1 + (int)words[next].length();
                next++;
            }

            char buffer[maxWidth+1];
            memset(buffer, ' ', maxWidth);
            buffer[maxWidth] = '\0';

            int interval = next - 1 - pos;
            double remain_length = maxWidth - length_sofar;
            int copy_pos = 0;
            for(int i=pos; i<next; i++){
                words[i].copy(buffer+copy_pos, words[i].length(), 0);
                if(next != len){
                    int skip = ceil(remain_length / interval--);
                    remain_length -= skip;
                    copy_pos += words[i].length() + skip + 1;
                }else{
                    copy_pos += words[i].length() + 1;
                }
            }
            pos = next;
            lines.push_back(string(buffer));
        }
        return lines;
    }
};
