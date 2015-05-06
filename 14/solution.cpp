#include "../solution.h"
struct TrieNode{
    char c;
    TrieNode *children[256];
    TrieNode(char c){
        this->c = c;
        for(int i=0; i<256; i++){
            children[i] = NULL;
        }
    }
};

class Solution{
    public:
        string longestCommonPrefix(vector<string> &strs){
            // trivial case
            if(strs.empty())
                return "";
            else if(strs.size() == 1)
                return strs[0];

            // initialization
            TrieNode *root = new TrieNode('\0');
            string longest_common_prefix = "";
            insert(root, strs[0]);

            for(int i=1; i<(int)strs.size(); i++){
                string longest = insert(root, strs[i]);
                if(longest.length() > longest_common_prefix.length())
                    longest_common_prefix = longest;
            }
            return longest_common_prefix;
        }

        string insert(TrieNode *root, string &str){
            int length = 0;
            TrieNode *ptr = root;
            for(int i=0; i<(int)str.size(); i++){
                char c = str[i];
                int c_int = (int)c;
                if(ptr->children[c_int] == NULL){
                    ptr->children[c_int] = new TrieNode(c);
                }else{
                    length++;
                }
                ptr = ptr->children[c_int];
            }
            return str.substr(0,length);
        }
};
