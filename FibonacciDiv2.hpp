#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class FibonacciDiv2{
public:
    int find(int N){
        vector<int> fibMem;
        fibMem.push_back(0);
        fibMem.push_back(1);
        if (N == 0 || N == 1){
            return 0;
        }

        int oldDifference = numeric_limits<int>::max();
        int newDifference;
        while (true){
            fibMem.push_back(fibMem.end()[-1] + fibMem.end()[-2]);
            newDifference = abs(N - fibMem.back());

            if (newDifference == 0){
                return 0;
            } else if (newDifference < oldDifference){
                oldDifference = newDifference;
            } else if (newDifference > oldDifference){
                return oldDifference;
            }
        }
    }
};