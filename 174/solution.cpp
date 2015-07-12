#include "../solution.h"
class Solution {
public:
    // greedy search, however wrong
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int height = dungeon.size();
        int width = dungeon[0].size();
        int HP[width];
        memset(HP, 1000, width*sizeof(HP[0]));

        HP[0] = 1 + max(0, 1 - ( 1 + dungeon[0][0]));
        dungeon[0][0] = max(1, 1 + dungeon[0][0]);
        // cout<<"hp:"<<HP[0]<<"dungeon:"<<dungeon[0][0]<<endl;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(i==0 && j==0) continue;
                int from_left_hp = INT_MAX;
                int from_left_path = -1;
                int from_top_hp = INT_MAX;
                int from_top_path = -1;
                if(j>0){
                    int path = dungeon[i][j-1] + dungeon[i][j];
                    from_left_hp = HP[j-1] + max(1-path, 0);
                    from_left_path = max(1, path);
                }
                if(i>0){
                    int path = dungeon[i-1][j] + dungeon[i][j];
                    from_top_hp = HP[j] + max(1-path, 0);
                    from_top_path = max(1, path);
                }

                // update HP[i]
                HP[j] = min(from_left_hp, from_top_hp);

                // update dungeon[i][j]
                if(from_left_hp < from_top_hp)
                    dungeon[i][j] = from_left_path;
                else if(from_left_hp > from_top_hp)
                    dungeon[i][j] = from_top_path;
                else
                    dungeon[i][j] = max(from_left_path, from_top_path);

            // cout<<"hp:"<<HP[j]<<"dungeon:"<<dungeon[i][j]<<endl;
            }
        }
        // for(int i=0; i<length; i++){
            // for(int j=0; j<length; j++){
                // cout<<dungeon[i][j]<<" ";
            // }
            // cout<<endl;
        // }
        return HP[width-1];
    }
};
