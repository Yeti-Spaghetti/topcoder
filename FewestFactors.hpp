#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
using namespace std;

class FewestFactors{
public:
    int number(vector<int> digits){
        vector<string> str_digits;
        for (int i = 0; i < digits.size(); i++){
            str_digits.push_back(to_string(digits[i]));
        }
        
        // concatenate all numbers into a string and sort
        string s;
        for (int i = 0; i < str_digits.size(); i++){
            s += str_digits[i];
        }
        sort(s.begin(), s.end());

        // permute and push into vector
        vector<int> permutes;
        do {
            permutes.push_back(stoi(s));
        } while (next_permutation(s.begin(), s.end()));

        // each factor, increase counter by 2
        int minFactors = numeric_limits<int>::max();
        int index;
        for (int i = 0; i < permutes.size(); i++){
            int factors = 2;
            cout << permutes[i] << endl;
            for (int j = 2; j < sqrt(permutes[i])+1; j++){
                if (permutes[i] % j == 0){
                    if (j * j == permutes[i]){
                        factors += 1;
                    } else {
                        factors += 2;
                    }
                }
            }

            cout << factors << endl;

            if (factors < minFactors){
                minFactors = factors;
                index = i;
            }
            if (factors == minFactors){
                if (permutes[i] < permutes[index]){
                    index = i;
                }
            }
        }
        return permutes[index];
    }
};