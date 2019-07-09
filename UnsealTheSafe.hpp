#include <bits/stdc++.h>
using namespace std;

class UnsealTheSafe{
public:
    long countPasswords(int n){
        n -= 2;
        long count = 0;
        vector<long> vec1 = {2,3,2,3,4,3,3,3,2,1};
        vector<long> vec2 = {0,0,0,0,0,0,0,0,0,0};

        for (int i = 0; i < n; i++){
            vec2[0] = vec1[1] + vec1[3];
            vec2[1] = vec1[0] + vec1[2] + vec1[4];
            vec2[2] = vec1[1] + vec1[5];
            vec2[3] = vec1[0] + vec1[4] + vec1[6];
            vec2[4] = vec1[1] + vec1[3] + vec1[5] + vec1[7];
            vec2[5] = vec1[2] + vec1[4] + vec1[8];
            vec2[6] = vec1[3] + vec1[7] + vec1[9];
            vec2[7] = vec1[4] + vec1[6] + vec1[8];
            vec2[8] = vec1[7] + vec1[5];
            vec2[9] = vec1[6];
            vec1 = vec2;
        }

        for (auto i : vec1){
            count += i;
        }
        
        return count;
    }
};

/* 
UnsealTheSafe:
- without the first and second public test case, 
  i wouldn't have been able to draw the table up and recognise the pattern
- the algorithm is easy from then on i reckon
- create an array of length 10 and fill with the number of possible next choices for each number
- so the array would look like this [2,3,2,3,4,3,3,3,2,1]
- then run a loop 'n - 2' amount of times
- do the addition each loop
- return count

- i discovered i need to use vectors instead of arrays and that i need two vectors.
- need two vectors because the values that are being summed need to remain the same for other additions
- they need to be vectors because after all the addition in each loop, i need to change make one vector equal to another

- i delayed doing this problem for 2 weeks because i was trying to think of this problem as a recursive problem
- on a whim i made a table and GUESSED that for N = 3, it was the sum of the numbers next to each digit
 */