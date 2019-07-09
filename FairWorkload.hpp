#include <bits/stdc++.h>
using namespace std;

class LostParentheses{
public:
    int minResult(string e){
        int min = 0
        int found = e.find('-');

        
        int numStart = 0, numEnd = 0;
        // if no negatives
        if (found == string::npos){
            for (int i = 0; i < e.length(); i++){
                numEnd = e.find('+', numStart);
                string num = e.substr(numStart, numEnd - numStart);
                cout << num << " ";
                min += stoi(num);
                numStart = numEnd+1;
            }
        }
    }
};