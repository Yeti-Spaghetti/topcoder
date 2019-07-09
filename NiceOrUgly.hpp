#include <bits/stdc++.h>
using namespace std;

class NiceOrUgly{
public:
    string describe(string s){
        vector<char> vowelArray = {'A', 'E', 'I', 'O', 'U'};

        // convert string to a string of 'c' and 'v'
        for (int i = 0; i < s.length(); i++){
            bool charVowel = false;
            for (int j = 0; j < vowelArray.size(); j++){
                if (s[i] == vowelArray[j]){
                    s[i] == 'V';
                    charVowel = true;
                    break;
                }
            }

            if (!charVowel){
                s[i] == 'C';
            }
            
        }
        // helper(s, 0, 0, 0, 0,);
    }

    helper(string s, int cons, int vowl, int isNice, int isUgly){

    }
};