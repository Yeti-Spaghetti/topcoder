#include <bits/stdc++.h>
using namespace std;

class MinimalDifference{
public:
    int findNumber(int A, int B, int C){
        int tempC = C;
        int cDigitSum = 0;
        while (tempC != 0){
            cDigitSum += tempC % 10;
            tempC /= 10;
        }

        int returnVal, diff = INT_MAX;
        while (A != B+1){
            int tempA = A;
            int xDigitSum = 0;
            while(tempA != 0){
                xDigitSum += tempA % 10;
                tempA /= 10;
            }

            int absoluteVal = abs(xDigitSum - cDigitSum);
            if (absoluteVal < diff){
                diff = absoluteVal;
                returnVal = A;
            }
            A++;
        }
        return returnVal;
    }
    // hidden message
};