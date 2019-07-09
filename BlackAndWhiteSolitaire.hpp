#include <bits/stdc++.h>
using namespace std;

class BlackAndWhiteSolitaire{
public:
    int minimumTurns(string cardFront){
        int length = cardFront.length();
        string sol1;
        string sol2;

        // create two solutions
        for (int i = 0; i < length; i++){
            if (i % 2 == 0){
                sol1 += "B";
                sol2 += "W";
            } else {
                sol1 += "W";
                sol2 += "B";
            }
        }

        if (cardFront == sol1 || cardFront == sol2){
            return 0;
        } else {
            int min1 = 0, min2 = 0;
            for (int i = 0; i < length; i++){
                if (cardFront[i] != sol1[i]){
                    min1++;
                }
                if (cardFront[i] != sol2[i]){
                    min2++;
                }
            }
            if (min1 < min2){
                return min1;
            } else {
                return min2;
            }
        }
    }
};

/* 
- find string length
- create the two alternating card solutions using a loop
- check if any of the solutions match the string argument
- otherwise run another loop and check which solution has the least amount of changes
 */