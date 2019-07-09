#include <bits/stdc++.h>
using namespace std;

class RugSizes{
public:
    int rugCount(int area){
        int divisor, count = 0;
        for (int i = 1; i < sqrt(area)+1; i++){
            if (area % i == 0){
                divisor = area / i;
                if (i <= divisor){
                    if (divisor == i){
                        //cout << divisor << "x" << i << endl;
                        count++;
                    } else if (divisor % 2 == 1 || i % 2 == 1){
                        //cout << divisor << "x" << i << endl;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};