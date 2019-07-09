#include <bits/stdc++.h>
using namespace std;

class TimeTravellingCellar{
public:
    int determineProfit(vector<int> profit, vector<int> decay){
        int max = 0, imax = 0;
        int min = 10001, imin = 0;
        int size = profit.size();
        
        for (int i = 0; i < size; i++){
            if (profit[i] > max){
                max = profit[i];
                imax = i;
            }
            if (decay[i] < min){
                min = decay[i];
                imin= i;
            }
        }

        // if max profit and min decay are the same cellar
        if (imax == imin){
            int alt_max = 0, alt_min = 10001;
            int alt_imax = 0, alt_imin = 0;

            // search for next max and min
            for (int i = 0; i < size; i++){
                if (profit[i] > alt_max && i != imax){
                    alt_max = profit[i];
                    alt_imax = i;
                }
                if (decay[i] < alt_min && i != imin){
                    alt_min = decay[i];
                    alt_imin = i;
                }
            }
            // get greatest profit
            if ((max - alt_max) < (alt_min - min)){
                imax = alt_imax;
            } else {
                imin = alt_imin;
            }
        }
        return profit[imax] - decay[imin];
    }
};