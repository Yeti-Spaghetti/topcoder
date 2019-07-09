#include <bits/stdc++.h>
using namespace std;

class Barbecue{
public:
    int eliminate(int n, vector<int> voter, vector<int> exclude){
        vector<int> noMeat;
        for (int i = 0; i < n; i++){
            noMeat.push_back(0);
        }

        for (int i = 0; i < voter.size(); i++){
            noMeat[voter[i]]++;
            noMeat[exclude[i]] += 50;
        }
        
        for (auto i : noMeat){
            cout << i << " ";
        }
        cout << endl;

        int max = 0, index = 0;
        for (int i = 0; i < noMeat.size(); i++){
            if (noMeat[i] > max){
                max = noMeat[i];
                index = i;
            }
        }
        return index;
    }
};