#include <bits/stdc++.h>
using namespace std;

class ProblemsToSolve{
public:
    int minNumber(vector<int> pleasantness, int variety){
        vector<double> jumps;
        int n = pleasantness.size();
        if (n == 1){
            return 1;
        }

        for (double i = 0; i < n-1; i++){
            
            for (double j = i+1; j < n; j++){
                int diff = abs(pleasantness[i]-pleasantness[j]);
                if (diff >= variety){
                    double pushVal = ceil((j-i)/2) + ceil(i/2);
                    jumps.push_back(pushVal);
                }
            }
        }

        if (jumps.size() == 0){
            return n;
        }

        return 1+*min_element(jumps.begin(), jumps.end());
    }
};