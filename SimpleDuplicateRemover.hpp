#include <bits/stdc++.h>
using namespace std;

class SimpleDuplicateRemover{
public:
    vector<int> process(vector<int> sequence){
        vector<int> existing;
        for (int i = sequence.size()-1; i >= 0; i--){
            bool exists = false;
            for (int j = 0; j < existing.size(); j++){
                if (sequence[i] == existing[j]){
                    exists = true;
                }
            }

            if (exists){
                sequence.erase(sequence.begin() + i);
            } else {
                existing.push_back(sequence[i]);
            }
        }
        return sequence;
    }
};

/* 
SimpleDuplicateRemover:
- can run through the loop and fill a vector 'repeats'
- each iteration we check if that number exists in the vector
- otherwise append it to 
- O(n^2)
- i wonder if it can be done in faster time? unlikely.
 */