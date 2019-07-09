#include <bits/stdc++.h>
using namespace std;

class QuickSums{
private:
    int countPlusses = INT_MAX;
    bool found = false;
public:
    int calcSum(string num){
        int it = 0;
        int sum = 0;
        while(it != string::npos){
            int it2 = num.find('+', it+1);
            int convert = stoi(num.substr(it, it2));
            sum += convert;
            it = it2;
        }
        return sum;
    }

    int minSums(string num, int target){
        return helper(num, target, 0);
    }

    int helper(string num, int target, int plusses){
        if (plusses == 0){
            countPlusses = INT_MAX;
            found = false;
        }
        // initial case
        if (num.find('+') == string::npos && plusses == 0){
            if (stol(num) == target){
                return 0;
            }
        }
        
        // insert first '+' and move it each loop
        for (int i = 1; i < num.length(); i++){
            int tempPlusses = plusses;
            string copy = num;
            copy.insert(i, "+");
            tempPlusses++;
            //cout << copy << endl;

            // check if string equals target
            if (calcSum(copy) == target){
                found = true;
                if (tempPlusses < countPlusses){
                    //cout << tempPlusses << ": " << copy << endl;
                    countPlusses = tempPlusses;
                }
            }

            int plusPos = copy.find('+');
            int subtractNum = stoi(copy.substr(0, plusPos));
            if (subtractNum <= target){
                string substring = copy.substr(plusPos+1);
                helper(substring, target-subtractNum, tempPlusses);
            }
        }
        if (found){
            return countPlusses;
        } else {
            return -1;
        }
        
    }
};