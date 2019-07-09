#include <bits/stdc++.h>
using namespace std;

class NumberSplit{
private:
    int max;
public:
    int longestSequence(int start){
        max = INT_MIN;
        recursiveCall(start, 0);
    }

    int recursiveCall(int start, int count){
        count++;
        // base case
        if (start <= 9){
            if (count > max){
                max = count;
            }
        }

        else if (start <= 99){
            int num2 = start % 10;
            int num1 = start / 10;
            int multNum = num1 * num2;
            recursiveCall(multNum, count);
        }

        else if (start <= 999){
            vector<string> binary;
            for (int i = 1; i <= 3; i++){
                bitset<2> bit(i);
                binary.push_back(bit.to_string());
            }

            for (int i = 0; i < binary.size(); i++){
                int array[3] = {1,1,1};
                int tempStart = start;
                for (int j = 0; j < 2; j++){
                    if (binary[i][j] == '1'){
                        int power = 2-j;
                        int divisor = pow(10, power);
                        array[j] = tempStart / divisor;
                        tempStart %= divisor;
                    }
                }
                array[2] = tempStart;

                int multSum = 1;
                for (int i = 0; i < 3; i++){
                    if (array[i] != 1){
                        multSum *= array[i];
                    }
                }
                recursiveCall(multSum, count);
            }
        }

        else if (start <= 9999){
            vector<string> binary;
            for (int i = 1; i <= 7; i++){
                bitset<3> bit(i);
                binary.push_back(bit.to_string());
            }

            for (int i = 0; i < binary.size(); i++){
                int array[4] = {1,1,1,1};
                int tempStart = start;
                for (int j = 0; j < 3; j++){
                    if (binary[i][j] == '1'){
                        int power = 3-j;
                        int divisor = pow(10, power);
                        array[j] = tempStart / divisor;
                        tempStart %= divisor;
                    }
                }
                array[3] = tempStart;

                int multSum = 1;
                for (int i = 0; i < 4; i++){
                    if (array[i] != 1){
                        multSum *= array[i];
                    }
                }
                recursiveCall(multSum, count);
            }
        }

        else if (start <= 99999){
            vector<string> binary;
            for (int i = 1; i <= 15; i++){
                bitset<4> bit(i);
                binary.push_back(bit.to_string());
            }

            for (int i = 0; i < binary.size(); i++){
                int array[5] = {1,1,1,1,1};
                int tempStart = start;
                for (int j = 0; j < 4; j++){
                    if (binary[i][j] == '1'){
                        int power = 4-j;
                        int divisor = pow(10, power);
                        array[j] = tempStart / divisor;
                        tempStart %= divisor;
                    }
                }
                array[4] = tempStart;

                int multSum = 1;
                for (int i = 0; i < 5; i++){
                    if (array[i] != 1){
                        multSum *= array[i];
                    }
                }
                recursiveCall(multSum, count);
            }
        }

        else if (start == 100000){
            return 2;
        }
        
        return max;
    }
};