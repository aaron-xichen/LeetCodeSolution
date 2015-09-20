#include "../solution.h"
struct TrieNode{
    char c;
    int count;
    TrieNode *children[4];
    // A - 0, C -1, G - 2, T - 3
    TrieNode(char cc): c(cc), count(0){
        for(int i=0; i<4; i++)
            children[i] = NULL;
    };
};

void insert(TrieNode *root, string seq, unordered_map<char, int> &m){
    for(int i=0; i<(int)seq.size(); i++){
        char c = seq[i];
        int idx = m.find(c)->second;
        if(!root->children[idx]){
            root->children[idx] = new TrieNode(c);
        }
        root = root->children[idx];
    }
    root->count++;
}

void collectAll(vector<string> &ans, TrieNode *cur, string cur_str, unordered_map<char, int> &m){
    // cout<<cur_str<<endl;
    if(cur_str.size() == 10){
        if(cur->count >= 2)
            ans.push_back(cur_str);
        return;
    }

    for(unordered_map<char, int>::iterator it=m.begin(); it!=m.end(); it++){
        char c = it->first;
        int idx = it->second;
        if(cur->children[idx]){
            collectAll(ans, cur->children[idx], cur_str + c, m);
        }
    }
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        TrieNode *root = new TrieNode('0');
        unordered_map<char, int> m;
        m.insert(pair<char, int>('A', 0));
        m.insert(pair<char, int>('C', 1));
        m.insert(pair<char, int>('G', 2));
        m.insert(pair<char, int>('T', 3));
        for(int i=0; i<=(int)s.size() - 10; i++){
            string sub = s.substr(i, 10);
            insert(root, sub, m);
        }

        vector<string> ans;
        if(10 > (int)s.length())
            return ans;

        string cur_str;
        collectAll(ans, root, cur_str, m);
        return ans;
    }
};
