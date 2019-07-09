#include <string>
#include <vector>
using namespace std;

class Reppity{
public:
    int longestRep(string input){
        vector<string> substrVector;
        vector<int> stringStart;
        vector<int> stringEnd;
        for (int i = 0; i < input.length(); i++){
            for (int j = 1; j < input.length()+1-i; j++){
                string substr = input.substr(i, j);
                substrVector.push_back(substr);
                stringStart.push_back(i);
                stringEnd.push_back(i+substr.length());
            }
        }

        int index = 0;
        int longestLength = 0;
        bool found = false;
        for (int i = 0; i < substrVector.size(); i++){
            for (int j = i+1; j < substrVector.size(); j++){
                if (substrVector[i] == substrVector[j] && stringEnd[i] <= stringStart[j]){
                    if (substrVector[j].length() > longestLength){
                        longestLength = substrVector[j].length();
                        index = j;
                        found = true;
                    }
                }
            }
        }
        if (found){
            return substrVector[index].length();
        } else {
            return 0;
        }
    }
};