#include <bits/stdc++.h>
using namespace std;

class GoodHours{
public:
    int howMany(string before, string after){

        // remove colon
        before.erase(before.begin()+2);
        after.erase(after.begin()+2);

        int good = 0;
        
        while (before != after){
            bool bGood = false;
            for (int i = 0; i < 3; i++){
                int num1 = 1, num2 = 1;
                // split before into two
                string substr1 = before.substr(0, i+1);
                string substr2 = before.substr(i+1, before.length());
                // multiply each digit in the substrings
                for (int j = 0; j < substr1.length(); j++){
                    if (substr1[j] == '0'){
                        num1 = 0;
                        break;
                    }
                    num1 *= substr1[j] - '0';
                }
                for (int j = 0; j < substr2.length(); j++){
                    if (substr2[j] == '0'){
                        num2 = 0;
                        break;
                    }
                    num2 *= substr2[j] - '0';
                }
                if (num1 == num2){
                    bGood = true;
                    break;
                }
            }
            if (bGood){
                good++;
            }

            // increment time
            int intBefore = stoi(before);
            intBefore += 1;
            if (intBefore % 100 == 60){
                intBefore -= 60;
                intBefore += 100;
            }
            if (intBefore == 2400){
                intBefore = 0;
            }
            before = to_string(intBefore);

            // add leading zeros when needed
            while (before.length() < 4){
                before.insert(0, 1, '0');
            }
        }
        
        // check one last time
        bool bGood = false;
        for (int i = 0; i < 3; i++){
            int num1 = 1, num2 = 1;
            string substr1 = before.substr(0, i+1);
            string substr2 = before.substr(i+1, before.length());
            for (int j = 0; j < substr1.length(); j++){
                if (substr1[j] == '0'){
                    num1 = 0;
                    break;
                }
                num1 *= substr1[j] - '0';
            }
            for (int j = 0; j < substr2.length(); j++){
                if (substr2[j] == '0'){
                    num2 = 0;
                    break;
                }
                num2 *= substr2[j] - '0';
            }
            if (num1 == num2){
                bGood = true;
            }
        }
        if (bGood){
            good++;
        }
        return good;
    }
};