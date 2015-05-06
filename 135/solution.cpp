#include "../solution.h"
class Solution{
    public:
        int candy(vector<int> &ratings){
            int len = ratings.size();
            // trivial case
            if(len == 0)
                return 0;
            else if(len == 1)
                return 1;

            int lo = 0;
            int lt = 0;
            int gt = 0;
            int total = 0;
            for(int i=1; i<len; i++){
                if(ratings[i] != ratings[i-1]){
                    if(lt != gt){
                        total += noDuplicated(ratings, lo, lt);
                        total += gt - lt - 1;
                        lo = gt;
                    }
                    lt = i;
                    gt = i;
                }else{
                    gt = i;
                }
            }
            total += noDuplicated(ratings, lo, lt);
            total += gt - lt;
            return total;
        }

        int noDuplicated(vector<int> &ratings, int lo, int hi){
            if(lo == hi)
                return 1;
            int previous_peak_index = lo;
            int previous_peak_hight = 1;

            int current_hight = 1;
            int total = 1;
            for(int i=lo+1; i<=hi; i++){
                if(ratings[i] > ratings[i-1]){
                    previous_peak_index= i;
                    current_hight += 1;
                    previous_peak_hight = current_hight;
                    total += current_hight;
                }else if(ratings[i] < ratings[i-1]){
                    current_hight = 1;
                    if(i - previous_peak_index < previous_peak_hight)
                        total += i - previous_peak_index;
                    else
                        total += i - previous_peak_index + 1;
                }else{
                    cout<<"fatal error"<<endl;
                }
            }
            return total;
        }
};
