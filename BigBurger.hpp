#include <bits/stdc++.h>
using namespace std;

class BigBurger{
public:
    int maxWait(vector<int> arrival, vector<int> service){
        int n = arrival.size();
        
        if (n == 1){
            return 0;
        }

        int minutes = 0;
        vector<int> wait;
        for (int i = 0; i < n; i++){
            cout << i << endl;
            if (minutes <= arrival[i]){
                minutes = arrival[i] + service[i];
            } else {
                int timeWaited = minutes - arrival[i];
                wait.push_back(timeWaited);
                minutes += service[i];
            }
        }

        int max = 0;
        for (int i = 0; i < wait.size(); i++){
            if (wait[i] > max){
                max = wait[i];
            }
        }
        return max;
    }
};