#include <bits/stdc++.h>
using namespace std;

class Multiples{
public:
    int number(int min, int max, int factor){
        int count = 0;
        int num;
        for (int i = min; i <= max; i++){
            if (i % factor == 0){
                num = i;
                while (num <= max){
                    num += factor;
                    count++;
                }
                break;
            }
        }
        return count;
    }
};

/* 
Multiples:
- run a loop beginning at min, ending at max, incrementing by 1 each time
- if increment mod factor equals 0, increase int variable 'counter' by 1

- i think i can reduce the running time by a lot for large difference between min and mix
- this can have quite a long running time for a large negative min and large positive max
- my alternative is to still run a loop until iteratation mod factor equals 0,
but on that first mod = 0, make 'num' variable equal 'i', then while num less than or equal to max, 
increment num by factor and increase 'counter' by 1 each loop.
- thus i don't have to do an exhaustive mod check from min to max
 */