#include <bits/stdc++.h>
using namespace std;

class CorporationSalary{
public:
    long totalSalary(vector<string>relations){
        int n = relations.size();
        int salary[n];
        for (int i = 0; i < n; i++){
            salary[i] = 0;
        }
        int count = 0;

        for (int i = 0; i < n; i++){
            if (relations[i].find('Y') == string::npos){
                salary[i] = 1;
                count++;
            }
        }

        while (count != n){
            for (int i = 0; i < n; i++){
                if (salary[i] == 0){
                    bool canCalc = true;
                    int sum = 0;
                    for (int j = 0; j < n; j++){
                        // check if can calculate employee
                        if (relations[i][j] == 'Y' && salary[j] == 0){
                            canCalc = false;
                            break;
                        }
                        if (relations[i][j] == 'Y' && salary[j] != 0){
                            sum += salary[j];
                        }
                    }
                    if (canCalc){
                        salary[i] = sum;
                        count++;
                    }
                }
            } 
        }
        
        long totalSalary = 0;
        for (auto i : salary){
            totalSalary += i;
        }

        return totalSalary;
    }
};