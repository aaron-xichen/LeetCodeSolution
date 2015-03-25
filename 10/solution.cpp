#include<iostream>
using namespace std;
class Solution{
    public:
        bool isMatch(const char*s, const char *p){
            if(!*p) return (!*s);

            int m = strlen(s);
            int n = strlen(p);
            bool b[m+1][n+1];

            // initialize the b[0][0]
            b[0][0] = true;
            b[0][1] = false;
            for(int i=1; i<=m; i++){
                b[i][0] = false;
                b[i][1] = false;
            }

            b[1][1] = (p[0] == s[0] || p[0] == '.');

            // initialize b[0][1]-b[0][m]
            for(int j=1; j<n; j++){
                b[0][j+1] = (p[j] == '*' && b[0][j-1]);
            }

            for(int i=0; i<m; i++){
                for(int j=1; j<n; j++){
                    if(p[j] != '*'){
                        b[i+1][j+1] = b[i][j] && (p[j] == '.' || p[j] == s[i]);
                    }else{
                        b[i+1][j+1] = b[i+1][j-1] || b[i+1][j] ||
                            (b[i][j+1] && (p[j-1] == '.' || p[j-1] == s[i]));
                    }
                }
            }

            for(int i=0; i<=m; i++){
                for(int j=0; j<=n; j++){
                    cout<<b[i][j]<<" ";
                }
                cout<<endl;
            }
            return b[m][n];
        }
};
