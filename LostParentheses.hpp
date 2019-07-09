#include <bits/stdc++.h>
using namespace std;

class LostParentheses{
public:
    int minResult(string e){
        int min = 0;
        int findMinus = e.find('-');
        int findPlus = e.find('+');
        int numStart = 0, numEnd = 0;

        // if no minus and no plus
        if (findMinus == string::npos && findPlus == string::npos){
            return stoi(e);
        }
        // if no minus but yes plus
        if (findMinus == string::npos && findPlus != string::npos){
            while (true){
                numEnd = e.find('+', numStart);
                if (numEnd == string::npos){
                    string num = e.substr(numStart, e.length() - numStart);
                    min += stoi(num);
                    return min;
                }
                string num = e.substr(numStart, numEnd - numStart);
                min += stoi(num);
                numStart = numEnd+1;

                
            }
        }
        // if yes minus but no plus
        if (findMinus != string::npos && findPlus == string::npos){
            numEnd = e.find('-', numStart);
            string num = e.substr(numStart, numEnd - numStart);
            min += stoi(num);
            numStart = numEnd+1;

            while (true){
                numEnd = e.find('-', numStart);
                if (numEnd == string::npos){
                    num = e.substr(numStart, e.length() - numStart);
                    min -= stoi(num);
                    return min;
                }
                num = e.substr(numStart, numEnd - numStart);
                min -= stoi(num);
                numStart = numEnd+1;
            }
        }
        // if yes minus and yes plus
        if (findMinus != string::npos && findPlus != string::npos){
            while (true){
                numEnd = e.find('-', numStart);

                // check if reach end of string
                if (numEnd == string::npos){
                    // convert remaining additions
                    string substring = e.substr(numStart, e.length() - numStart);
                    int tempNum = minResult(substring);
                    string tempString = to_string(tempNum);
                    e.erase(numStart, e.length() - numStart);
                    e.insert(numStart, tempString);

                    // should be no more + in 'e' string
                    return minResult(e);
                }

                string substring = e.substr(numStart, numEnd - numStart);
                // cout << "Substring: " << substring << endl;
                if (substring.find('+') != string::npos){
                    int tempNum = minResult(substring);
                    string tempString = to_string(tempNum);
                    // cout << "Tempstring: " << tempString << endl;
                    e.erase(numStart, numEnd - numStart);
                    e.insert(numStart, tempString);
                    numEnd = numStart + tempString.length();
                }
                numStart = numEnd + 1;
            }
        }
    }
};