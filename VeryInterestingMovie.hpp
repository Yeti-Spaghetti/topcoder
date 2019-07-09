#include <bits/stdc++.h>
using namespace std;

class VeryInterestingMovie{
public:
    int maximumPupils(vector<string> seats){
        int returnVal = 0;
        for (int i = 0; i < seats.size(); i++){
            double count = 0;
            for (int j = 0; j < seats[i].length(); j++){
                if (seats[i][j] == 'Y'){
                    count++;
                } else if (count != 0 && seats[i][j] == 'N'){
                    returnVal += ceil(count/2);
                    count = 0;
                }
            }
            if (count != 0){
                returnVal += ceil(count/2);
            }
        }
        return returnVal;
    }
};