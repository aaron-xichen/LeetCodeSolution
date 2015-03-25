#include<iostream>
using namespace std;
class solution{
    public:
        bool isMatch(const char*s, const char*p){
            if(!*p) return (!*s);
            int m = strlen(s);
            int n = strlen(p);

            bool b[m+1][n+1];
            b[0][0] = true;
            for(int i=1; i<=m; i++){
                b[i][0] = false;
            }

            for(int j=0; j<n; j++){
                b[0][j+1] = p[j] == '*' && b[0][j];
            }

            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(p[j] == '*')
                        b[i+1][j+1] = b[i][j+1] || b[i][j] || b[i+1][j];
                    else if(p[j] == '?')
                        b[i+1][j+1] = b[i][j];
                    else
                        b[i+1][j+1] = b[i][j] && p[j] == s[i];
                }
            }
            return b[m][n];
        }
};
