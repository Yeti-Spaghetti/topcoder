#include <bits/stdc++.h>
using namespace std;

class PrefixFreeSets{
public: 
    int maxElements(vector<string> words){
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs)
        {
            return lhs.size() < rhs.size(); 
        });

        int count = 0;
        for (int i = 0; i < words.size(); i++){
            bool add = true;
            for (int j = i+1; j < words.size(); j++){
                if (words[j].find(words[i]) == 0){
                    add = false;
                }
            }
            if (add){
                count++;
            }
        }
        return count;
    }
};