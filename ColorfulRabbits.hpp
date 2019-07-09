#include <bits/stdc++.h>
using namespace std;

class ColorfulRabbits{
public:
    int getMinimum(vector<int> replies){
        map<int, int> bunnies;
        int numberOfBunnies = 0;

        for (int i = 0; i < replies.size(); i++){
            bunnies[replies[i]] += 1;
        }

        for (map<int, int>::iterator it = bunnies.begin(); it != bunnies.end(); it++){
            double num = it->first + 1;
            double replies = it->second;
            numberOfBunnies += num * ceil(replies / num);

        }
        return numberOfBunnies;
    }
};