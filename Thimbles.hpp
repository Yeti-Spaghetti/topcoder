#include <bits/stdc++.h>
using namespace std;

class Thimbles{
public:
    int thimbleWithBall(vector<string> swaps){
        string ballpos = "1";
        for (int i = 0; i < swaps.size(); i++){
            if (swaps[i].find(ballpos) == 0){
                ballpos = swaps[i][2];
            }
            else if (swaps[i].find(ballpos) == 2){
                ballpos = swaps[i][0];
            }
        }
        int returnVal = stoi(ballpos);
        return returnVal;
    }
};