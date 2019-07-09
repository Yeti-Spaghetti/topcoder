#include <bits/stdc++.h>
using namespace std;

class RunLengthEncoding{
public:
    string decode(string text){
        string returnText;
        int index = 0;
        for (int i = 0; i < text.length(); i++){
            if (!isdigit(text[i])){
                if (isdigit(text[i-1])){
                    string num = text.substr(index, i-index);
                    if (num.length() >= 3){
                        return "TOO LONG";
                    }
                    int repeat = stoi(num);
                    returnText.append(repeat, text[i]);
                    index = i+1;
                } else {
                    returnText.append(1, text[i]);
                    index = i+1;
                }
            }
        }
        if (returnText.length() > 50){
            return "TOO LONG";
        } else {
            return returnText;
        }
    }
};

