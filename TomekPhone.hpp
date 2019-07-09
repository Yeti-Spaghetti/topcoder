#include <bits/stdc++.h>
using namespace std;

class TomekPhone{
public:
    int minKeystrokes(vector<int> frequencies, vector<int> keySizes){
        // check if the keys can accommodate letters
        // calculate key spaces
        int sum = 0;
        for (int i = 0; i < keySizes.size(); i++){
            sum += keySizes[i];
        }
        if (sum < frequencies.size()){
            return -1;
        }

        int returnVal = 0, counter = 0, multiplier = 1;
        for (int i = 0; i < frequencies.size(); i++){

            // find max value
            int max = 0;
            int maxIndex = 0;
            for (int j = 0; j < frequencies.size(); j++){
                if (frequencies[j] > max){
                    max = frequencies[j];
                    maxIndex = j;
                }
            }

            frequencies[maxIndex] = 0;

            // if encounter 0 in keySizes, skip to next key
            while (keySizes[counter] == 0){
                counter++;
                if (counter >= keySizes.size()){
                    counter = 0;
                    multiplier++;
                }
            }

            // calculate sum
            if (keySizes[counter] != 0){
                returnVal += max * multiplier;
                keySizes[counter]--;
                counter++;
            }

            if (counter >= keySizes.size()){
                counter = 0;
                multiplier++;
            }
        }
        
        return returnVal;
    }
};