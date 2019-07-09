#include <bits/stdc++.h>
using namespace std;

class PaternityTest{
public:
    vector<int> possibleFathers(string child, string mother, vector<string> men){
        vector<int> dadCandidates;
        vector<int> nameMe;
        int count = 0;
        for (int i = 0; i < child.length(); i++){
            if (child[i] == mother[i]){
                nameMe.push_back(1);
                count++;
            } else {
                nameMe.push_back(0);
            }
        }
        
        /* cout << "nameMe" << '\n';
        for (auto i : nameMe){
            cout << i << " ";
        } */

        if (count == child.length() / 2){
            for (int i = 0; i < men.size(); i++){
                bool possibleDad = true;
                for (int j = 0; j < nameMe.size(); j++){
                    if (nameMe[j] == 0){
                        if (men[i][j] != child[j]){
                            possibleDad = false;
                            break;
                        }
                    }
                    
                }
                if (possibleDad){
                    cout << "Found dad? " << i <<  endl;
                    dadCandidates.push_back(i);
                }
            }
        }

        else if (count == child.length()){
            int toCheck = child.length() / 2;
            for (int i = 0; i < men.size(); i++){
                int check = 0;
                for (int j = 0; j < child.length(); j++){
                    if (men[i][j] == child[j]){
                        check++;
                    }
                    if (check == toCheck){
                        dadCandidates.push_back(i);
                        break;
                    }
                }
            }
        }

        else {
            int toCheck = 0;
            for (int i = 0; i < nameMe.size(); i++){
                if (nameMe[i] == 1){
                    toCheck++;
                }
            }
            toCheck = toCheck - child.length()/2;

            for (int i = 0; i < men.size(); i++){
                bool possibleDad = true;
                for (int j = 0; j < nameMe.size(); j++){
                    if (nameMe[j] == 0){
                        if (men[i][j] != child[j]){
                            possibleDad = false;
                            break;
                        }
                    }
                }
                int check = 0;
                if (possibleDad){
                    for (int j = 0; j < child.length(); j++){
                        if (men[i][j] == child[j] && nameMe[j] == 1){
                            check++;
                        }
                        if (check == toCheck){
                            dadCandidates.push_back(i);
                            break;
                        }
                    }
                }
            }

        }
        return dadCandidates;
    }
};
