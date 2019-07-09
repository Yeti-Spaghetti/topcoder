#include <bits/stdc++.h>
using namespace std;

class ImportantTasks{
public:
    int maximalCost(vector<int> complexity, vector<int> computers){
        sort(complexity.begin(), complexity.end());
        sort(computers.begin(), computers.end());
        reverse(complexity.begin(), complexity.end());
        reverse(computers.begin(), computers.end());

        int j = 0;
        int count = 0;
        for (int i = 0; i < complexity.size(); i++){
            if (complexity[i] <= computers[j]){
                j++;
                count++;
                if (j >= computers.size()){
                    break;
                }
            }
        }
        return count;
    }
};