#include <bits/stdc++.h>
using namespace std;

class ExerciseMachine{
public:
    int getPercentages(string time){
        int h, m, s = 0;
        double totalSeconds;
        if (sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s) >= 2){
            totalSeconds = h*3600 + m*60 + s;
        }
        cout << "Total seconds: " << totalSeconds << endl;
        
        double onePercent = totalSeconds/100;
        cout << "1% = " << onePercent << endl;

        int count = 0;
        /* for (int i = 1; i < 100; i++){
            double multiple = onePercent*i;
            // cout << onePercent << "*" << i << "=" << multiple << endl;
            // cout << int(multiple) << " : " << multiple << endl;
            if (int(multiple) == multiple){
                count++;
            }
        } */

        for (int i = 1; i < totalSeconds; i++){
            int num = i * 100 / totalSeconds;
            if (num * totalSeconds == i * 100){
                count++;
            }
        }


        return count;
    }
};